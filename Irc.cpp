/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:18 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/08 11:21:52 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Irc.hpp"

Irc::Irc(u_int16_t port, std::string password)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
	this->password = password;
	this->port = port;
	// second parameter is the size of the queue
	listen(sockfd, 5);
}

Irc::~Irc(){close(sockfd);}

void Irc::startConnection(User &aUser, std::string port, std::string password)
{
	if (password != this->password)
		this::theException("Nuh uh wrong password");
}

