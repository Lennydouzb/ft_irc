/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 10:11:42 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/16 17:32:17 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"

Channel::TheException::TheException(std::string msg)
{
	this->message = msg;
}
const char *Channel::TheException::what() const throw()
{
	return this->message.c_str();
}
Channel::TheException::~TheException() throw() {}


Channel::Channel(User& theOperator, std::string name)
{
	this->operators.push_back(&theOperator);
	this->users.push_back(&theOperator);
	this->name = name;
}

Channel::~Channel(){}

bool	Channel::checkPassword(std::string passwd)
{
	if (passwd == this->password)
		return true;
	return false;
}

bool	Channel::isUserIn(User& anUser)
{
	for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
	{
		if ((*it)->getNickname() == anUser.getNickname())
			return true;
	}
	return false;
}

bool	Channel::isUserOp(User& anUser)
{
	for (std::vector<User*>::iterator it = operators.begin(); it != operators.end(); ++it)
	{
		if ((*it)->getNickname() == anUser.getNickname())
			return true;
	}
	return false;
}

bool	Channel::isUserInvited(User& anUser)
{
	for (std::vector<User*>::iterator it = invited.begin(); it != invited.end(); ++it)
	{
		if ((*it)->getNickname() == anUser.getNickname())
			return true;
	}
	return false;
}
