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
	this->pollfds.push_back({sockfd, POLLIN, 0});
	this->isRunning = true;
}

Irc::~Irc(){close(sockfd);}

void Irc::startConnection(User &aUser, uint16_t port, std::string password)
{
	if (password != this->password)
		throw Irc::TheException("nuh uh");
	sockaddr_in
}

void Irc::run()
{
	while (this->isRunning)
	{
		while (poll(&this->pollfds[0], this->pollfds.size(), -1) < 0)
		{
			throw Irc::TheException("Error while polling");	
		}
		for (size_t i = 0; i < this->pollfds.size(); i++)
		{
			if (this->pollfds[i].revents & POLLIN)
			{
				if (this->pollfds[i].fd = this->sockfd)
				{
					int clientFd = accept(this->sockfd, NULL, NULL);
					if (clientFd < 0)
						throw Irc::TheException("Error while accepting a new client");
					this->pollfds.push_back({clientFd, POLLIN, 0});
				}
			}
		}
	}
}