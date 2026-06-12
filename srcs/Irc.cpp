/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:18 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/12 17:46:43 by ldesboui         ###   ########.fr       */
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
						this->Parser.parse(*(this->Users[i]), message);
					}
				}
			}
		}
	}
}

Irc::TheException::TheException(std::string msg)
{
	this->message = msg;
}
const char *Irc::TheException::what() const throw()
{
	return this->message.c_str();
}
Irc::TheException::~TheException() throw() {}
