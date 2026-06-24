/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:40 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 23:57:31 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/UserCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"
UserCommand::UserCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void UserCommand::exec()
{
	if (myArgs.size() == 4)
	{
		if (myUser.getIsPasswordVerified())
		{
			if (myUser.getUsername() == "")
			{
				myUser.setUsername(myArgs[0]);
				myUser.setRealname(myArgs[3]);
			}
			else
				myIrc.sendError(&myUser, NULL, ERR_ALREADYREGISTERED, "");

		}
		else
			myIrc.sendError(&myUser, NULL, ERR_NOTREGISTERED, "");

	}
	else
		myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "USER");
}

