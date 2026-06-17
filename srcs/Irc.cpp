/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:18 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:49:50 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Irc.hpp"
#include <netinet/in.h>

extern bool g_isrunning;
Irc::Irc(u_int16_t port, std::string password)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		throw Irc::TheException("Error while launching the server");
	int opt = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
		throw Irc::TheException("Something went wrong while launchine the server");
	this->password = password;
	this->port = port;
	// second parameter is the size of the queue
	if (listen(sockfd, 5) < 0)
		throw Irc::TheException("Something went wrong while launchine the server");
	pollfd serverPollfd;
	serverPollfd.fd = sockfd;
	serverPollfd.events = POLLIN;
	serverPollfd.revents = 0;
	User *srvUser = new User(sockfd, "", "");
	this->Users.push_back(srvUser);
	this->Users.back()->setpollfd(serverPollfd);
	this->messages.push_back("");
	g_isrunning = true;
}

Irc::~Irc()
{
	for (size_t i = 0; i < this->Users.size(); ++i) {
        delete this->Users[i];
    }
    this->Users.clear();
    this->messages.clear();
}

void Irc::run()
{
	while (g_isrunning)
	{
		std::vector<pollfd> fds;
		for (size_t idx = 0; idx < this->Users.size(); ++idx)
		{
			fds.push_back(this->Users[idx]->getpollfd());
		}
		if (fds.empty())
			continue;
		if (poll(&fds[0], fds.size(), -1) < 0)
		{
			throw Irc::TheException("Error while polling");	
		}
		for (size_t i = 0; i < fds.size(); i++)
		{
			//if its the server socket
			if (fds[i].fd == this->sockfd)
			{
				if (fds[i].revents & POLLIN)
				{
					int clientFd = accept(this->sockfd, NULL, NULL);
					fcntl(clientFd, F_SETFL, O_NONBLOCK);
					if (clientFd < 0)
						throw Irc::TheException("Error while accepting a new client");
					struct pollfd newClient;
					newClient.fd = clientFd;
					newClient.events = POLLIN;
					newClient.revents = 0;
					User *newUser = new User(clientFd, "", "");
					newUser->setpollfd(newClient);
					this->Users.push_back(newUser);
					this->messages.push_back(std::string());
				}
			}
			//if its client socket
			else
			{
				if (fds[i].revents & (POLLHUP | POLLNVAL | POLLERR))
					{
						delete this->Users[i];
						this->Users.erase(this->Users.begin() + i);
						this->messages.erase(this->messages.begin() + i);
						i--;
						continue;
					}
				else if (fds[i].revents & POLLIN)
				{
					char buffer[1024];
					memset(buffer, 0, sizeof(buffer));
					int bytesRead = recv(fds[i].fd, buffer, sizeof(buffer) - 1, 0);

					if (bytesRead < 0)
					{
						delete this->Users[i];
						this->Users.erase(this->Users.begin() + i);
						this->messages.erase(this->messages.begin() + i);
						i--;
						continue;
					}
					if (bytesRead == 0)
					{
						delete this->Users[i];
						this->Users.erase(this->Users.begin() + i);
						this->messages.erase(this->messages.begin() + i);
        				i--;
						continue;
					}
					buffer[bytesRead] = '\0';
					this->messages[i].append(buffer, bytesRead);
					size_t pos;
					while ((pos = this->messages[i].find('\n')) != std::string::npos)
					{
						std::string message = this->messages[i].substr(0, pos + 1);
						this->messages[i].erase(0, pos + 1);
						std::cout << message << std::endl;
						this->Parser.parse(*(this->Users[i]), message, *this);
					}
				}
			}
		}
	}
}

void	Irc::sendMessage(User &sender, User& receiver, std::string message)
{
	//user to user
	std::string prefix = ":" + sender.getNickname() + "!" + sender.getUsername() + "@127.0.0.1 ";
	if (message.size() < 2 || message.substr(message.size() - 2) != "\r\n")
    {
        message += "\r\n";
    }
	std::string entireMsg = prefix + "PRIVMSG " + receiver.getNickname() + " :" + message;
	ssize_t bytesRead = 0;
	while (!entireMsg.empty() && bytesRead != -1)
	{
		bytesRead = send(receiver.getSocket(), entireMsg.c_str(), entireMsg.length(), 0);
		if (bytesRead > 0)
			entireMsg.erase(0, bytesRead);
	}
	if (bytesRead == -1)
	{
		// error
		(void)bytesRead;
	}
}
void	Irc::sendMessage(User &sender, Channel& receiver, std::string message)
{
	//user to channel
	std::vector<User*>& users = receiver.getUsers();
	for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
	{
		if (*it != &sender)
		{
			sendMessage(sender, **it, message);
		}
	}
}

void	Irc::sendMessage(User& receiver, std::string message)
{
	//server to user
	std::string prefix = ":ft_irc ";
	if (message.size() < 2 || message.substr(message.size() - 2) != "\r\n")
    {
        message += "\r\n";
    }
	std::string entireMsg = prefix + message;
	ssize_t bytesRead = 0;
	while (!entireMsg.empty() && bytesRead != -1)
	{
		bytesRead = send(receiver.getSocket(), entireMsg.c_str(), entireMsg.length(), 0);
		if (bytesRead > 0)
			entireMsg.erase(0, bytesRead);
	}
	if (bytesRead == -1)
	{
		// error
		(void)bytesRead;
	}
}

std::vector<Channel*>& Irc::getChannels()
{
	return this->openedChannel;
}

bool	Irc::verifiyPass(std::string passwd)
{
	if (passwd == this->password)
		return true;
	return false;
}

void	Irc::addChannel(Channel& aChannel)
{
	this->openedChannel.push_back(&aChannel);
}

void Irc::addUser(User &anUser)
{
	if (anUser.getIsPasswordVerified())
		this->Users.push_back(&anUser);
}

Irc::TheException::TheException(std::string msg)
{
	this->message = msg;
}
const char *Irc::TheException::what() const throw()
{
	return this->message.c_str();
}

bool	Irc::checkExistingNick(std::string nick)
{
	for (std::vector<User*>::iterator it = Users.begin(); it != Users.end(); ++it)
	{
		if ((*it)->getNickname() == nick)
			return true;
	}
	return false;
}

bool	Irc::channelExist(std::string name)
{
	for (std::vector<Channel*>::iterator it = openedChannel.begin(); it != openedChannel.end(); ++it)
	{
		if (*it && (*it)->getName() == name)
			return true;
	}
	return false;
}

User&		Irc::getUser(std::string nick)
{
	for (std::vector<User*>::iterator it = Users.begin(); it != Users.end(); ++it)
	{
		if ((*it) && (*it)->getNickname() == nick)
			return *(*it);
	}
	throw Irc::TheException("User not found");
}

Channel&	Irc::getChannel(std::string name)
{
	for (std::vector<Channel*>::iterator it = openedChannel.begin(); it != openedChannel.end(); ++it)
	{
		if ((*it) && (*it)->getName() == name)
			return *(*it);
	}
	throw Irc::TheException("Channel not found");
}

Irc::TheException::~TheException() throw() {}
