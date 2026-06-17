/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:31 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:48:15 by ldesboui         ###   ########.fr       */
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
		if (!myIrc.checkExistingNick(myArgs[0]))
		{
			myUser.setNickname(myArgs[0]);
		}
	}
}

