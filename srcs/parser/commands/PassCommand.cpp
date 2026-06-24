/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:32 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 23:56:43 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/PassCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"

PassCommand::PassCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void PassCommand::exec()
{
	if (!myUser.getIsPasswordVerified())
	{
		if (myArgs.size() < 1)	
			myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "PASS");
		if (myIrc.verifiyPass(this->myArgs[0]))
		{
			myUser.verifyPassword();
		}
	}
	else
		myIrc.sendError(&myUser, NULL, ERR_ALREADYREGISTERED, "");
}

