/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:31 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 18:07:19 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/NickCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"

NickCommand::NickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void NickCommand::exec()
{
	if (myUser.getIsPasswordVerified())
	{
		if (myArgs.size() != 1)
		{
			myIrc.sendError(&myUser, NULL, NULL, ERR_NONICKNAMEGIVEN, "");
		}
		if (!myUser.isNickUsable(myArgs[0]))
		{
			myIrc.sendError(&myUser, NULL, NULL, ERR_ERRONEUSNICKNAME, myArgs[0]);
			return;
		}
		if (!myIrc.checkExistingNick(myArgs[0]))
			myUser.setNickname(myArgs[0]);
		else
			myIrc.sendError(&myUser, NULL, NULL, ERR_NICKNAMEINUSE, myArgs[0]);

	}
	else
		myIrc.sendError(&myUser, NULL, NULL, ERR_NOTEXTTOSEND, "");
}

