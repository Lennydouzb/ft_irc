/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:13 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/08 14:08:50 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"
#include <sys/socket.h>

User::User(int fd, std::string nickname, std::string username)
{
	this->nickname = nickname;
	this->username = username;
	this->socket = fd;
}

User::~User()
{
	if (this->socket > 0)
	{
		close(this->socket);
	}
}

void User::tryConnection(Irc &anIrc, uint16_t port, std::string password)
{
	anIrc.startConnection(*this, port, password);	
}

