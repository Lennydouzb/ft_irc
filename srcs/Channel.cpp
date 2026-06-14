/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 10:11:42 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/14 10:11:45 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::TheException::TheException(std::string msg)
{
	this->message = msg;
}
const char *Channel::TheException::what() const throw()
{
	return this->message.c_str();
}
Channel::TheException::~TheException() throw() {}


Channel::Channel(User& theOperator)
{

}

Channel::~Channel()
{

}

void Channel::sendMessage(User &sender, std::string message)
{

}

