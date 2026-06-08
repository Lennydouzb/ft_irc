/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:13 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/08 11:16:39 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"
#include <sys/socket.h>

User::User(std::string nickname, std::string username)
{
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
}

User::~User(){close(clientSocket);}

void User::tryConnection(Irc &anIrc, uint16_t port, std::string password)
{
	anIrc.startConnection(*this, port, password);	
}

