/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:13:13 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 13:17:34 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/User.hpp"
#include <sys/socket.h>

User::User(int fd, std::string nickname, std::string username)
{
	this->nickname = nickname;
	this->username = username;
	this->socket = fd;
	this->realname = "";
	this->isPasswordVerified = false;
}

User::~User()
{
	if (this->socket > 0)
	{
		close(this->socket);
	}
    close(this->pollfd.fd);
    

}
void User::verifyPassword()
{
	this->isPasswordVerified = true;
}

void User::setpollfd(struct pollfd pollfd)
{
	this->pollfd = pollfd;
}

struct pollfd User::getpollfd()
{
	return this->pollfd;
}

int User::getSocket()
{
	return this->socket;
}

std::string User::getNickname()
{
	return this->nickname;
}

std::string User::getUsername()
{
	return this->username;
}

bool User::getIsPasswordVerified()
{
	return this->isPasswordVerified;
}

void User::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void User::setUsername(std::string username)
{
	this->username = username;
}

std::string User::getRealname()
{
	return this->realname;
}

void		User::setRealname(std::string realname)
{
	this->realname = realname;
}

bool	User::isUserReady()
{
	if (getIsPasswordVerified() && !nickname.empty() && !username.empty() && !realname.empty())
		return true;
	return false;
}

std::string	User::getPrefix() const
{
    return ":" + this->nickname + "!" + this->username + "@127.0.0.1 ";
}

bool	User::isNickUsable(std::string nick) const
{
	for (std::string::iterator it = nick.begin(); it != nick.end(); ++it)
	{
		if (*it == ' ' || *it == ':' ||*it == '@' ||*it == '!' ||*it == '#' ||*it == '&' ||*it == '+' ||*it == '*' ||*it == '?' ||*it == ',' ||*it == '\r' ||*it == '\n' ||*it == '\0')
			return false;
	}
	return true;
}

std::string&	User::getSendBuffer()
{
	return this->sendBuffer;
}

void	User::addBuffer(std::string str)
{
	this->sendBuffer += str;
}
