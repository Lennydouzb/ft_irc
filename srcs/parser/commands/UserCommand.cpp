/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:40 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 14:06:39 by ldesboui         ###   ########.fr       */
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
		}
	}
}

