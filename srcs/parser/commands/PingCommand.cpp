/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/16 14:28:02 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/PingCommand.hpp"

PingCommand::PingCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void PingCommand::exec()
{
	if (myArgs[0].empty())
		myIrc.sendMessage(myUser, "PONG " + myArgs[0]);
	else
		myIrc.sendMessage(myUser, "PONG");

}

