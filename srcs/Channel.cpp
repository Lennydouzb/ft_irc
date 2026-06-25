/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 10:11:42 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 16:44:05 by ldesboui         ###   ########.fr       */
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
	this->isInviteOnly = false;
	this->userLimit = 0;
	this->restrictedTopic = false;
	this->password = "";
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

void	Channel::addUser(User &anUser)
{
	this->users.push_back(&anUser);
}
void	Channel::removeUser(User &anUser)
{
	for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
	{
		if ((*it)->getNickname() == anUser.getNickname())
		{
			users.erase(it);
			break;
		}
	}
	for (std::vector<User*>::iterator it = operators.begin(); it != operators.end(); ++it)
	{
		if ((*it)->getNickname() == anUser.getNickname())
		{
			operators.erase(it);
			break;
		}
	}
}

void	Channel::setPassword(std::string passwd)
{
	this->password = passwd;
}

void	Channel::setRestrictedTopic(bool val)
{
	this->restrictedTopic = val;
}

void	Channel::setName(const std::string &name)
{
	this->name = name;
}

void	Channel::setTopic(const std::string &topic)
{
	this->topic = topic;
}

void	Channel::setInviteOnly(bool val)
{
	this->isInviteOnly = val;
}

void	Channel::setUserLimit(size_t limit)
{
	this->userLimit = limit;
}

std::vector<User*>&	Channel::getOperators()
{
	return this->operators;
}

std::vector<User*>&	Channel::getUsers()
{
	return this->users;
}

const std::string&	Channel::getName() const
{
	return this->name;
}

const std::string&	Channel::getTopic() const
{
	return this->topic;
}

bool	Channel::getIsInviteOnly() const
{
	return this->isInviteOnly;
}

size_t	Channel::getUserLimit() const
{
	return this->userLimit;
}

bool	Channel::isRestrictedTopic() const
{
	return this->restrictedTopic;
}
