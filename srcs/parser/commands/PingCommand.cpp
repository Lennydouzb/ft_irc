/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:34 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 00:04:46 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/PingCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"

PingCommand::PingCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void PingCommand::exec()
{
	if (myArgs.size() < 1)
		myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "PING");
	else
		myIrc.sendMessage(myUser, "PONG "+ myArgs[0]);
}

