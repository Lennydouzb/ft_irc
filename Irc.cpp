/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:18 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/09 14:16:20 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Irc.hpp"
#include <netinet/in.h>

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
	this->pollfds.push_back(serverPollfd);

	this->isRunning = true;
}

Irc::~Irc(){close(sockfd);}

//void Irc::startConnection(User &aUser, u_int16_t port, std::string password)
//{
	//if (password != this->password)
//		throw Irc::TheException("nuh uh");
	//sockaddr_in
//}

void Irc::run()
{
	while (this->isRunning)
	{
		if (poll(&this->pollfds[0], this->pollfds.size(), -1) < 0)
		{
			throw Irc::TheException("Error while polling");	
		}
		for (size_t i = 0; i < this->pollfds.size(); i++)
		{
			//if its the server socket
			if (this->pollfds[i].fd == this->sockfd)
			{
				if (this->pollfds[i].revents & POLLIN)
				{
					int clientFd = accept(this->sockfd, NULL, NULL);
					if (clientFd < 0)
						throw Irc::TheException("Error while accepting a new client");
					struct pollfd newClient;
					newClient.fd = clientFd;
					newClient.events = POLLIN;
					newClient.revents = 0;
					this->pollfds.push_back(newClient);
				}
			}
			//if its client socket
			else
			{
				if (this->pollfds[i].revents & (POLLHUP | POLLNVAL | POLLERR))
					{
						close(this->pollfds[i].fd);
						this->pollfds.erase(this->pollfds.begin() + i);
						i--;
						continue;
					}
				else if (this->pollfds[i].revents & POLLIN)
				{
					char buffer[1024];
					memset(buffer, 0, sizeof(buffer));
					std::string message;
					int bytesRead = recv(this->pollfds[i].fd, buffer, sizeof(buffer), 0);
					while (bytesRead > 0)
					{
						message.append(buffer, bytesRead);
						memset(buffer, 0, sizeof(buffer));

						if (message.find("\n") != std::string::npos)
							break;
						bytesRead = recv(this->pollfds[i].fd, buffer, sizeof(buffer) - 1, 0);
					}
					if (bytesRead <= 0)
					{
						close(this->pollfds[i].fd);
						this->pollfds.erase(this->pollfds.begin() + i);
						i--;
						if (bytesRead < 0)
							throw Irc::TheException("Error while receiving message");
					}
					if (message.empty())
						continue;
					std::cout << "Received message: " << message << std::endl;
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