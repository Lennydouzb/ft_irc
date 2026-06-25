/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:31 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 20:37:55 by ldesboui         ###   ########.fr       */
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
			myIrc.sendError(&myUser, NULL, ERR_NONICKNAMEGIVEN, "");
			return ;
		}
		if (!myUser.isNickUsable(myArgs[0]))
		{
			myIrc.sendError(&myUser, NULL, ERR_ERRONEUSNICKNAME, myArgs[0]);
			return;
		}
		if (!myIrc.checkExistingNick(myArgs[0]))
		{
			myUser.setNickname(myArgs[0]);
			if (myUser.isUserReady() && !myUser.getIsWelcomed())
			{
				std::string srvPrefix = myUser.getPrefix() + " ";
				std::string nick = myUser.getNickname();
				std::string rpl001 = srvPrefix + "001 " + nick + " :Welcome to the ft_irc Network, " + nick + "!" + myUser.getUsername() + "@127.0.0.1\r\n";
				std::string rpl002 = srvPrefix + "002 " + nick + " :Your host is ft_irc, running version 1.0\r\n";
				std::string rpl003 = srvPrefix + "003 " + nick + " :This server was created today\r\n";
				std::string rpl004 = srvPrefix + "004 " + nick + " ft_irc 1.0 o itkol\r\n";
				myIrc.sendMessage(myUser, rpl001);
				myIrc.sendMessage(myUser,rpl002);
				myIrc.sendMessage(myUser,rpl003);
				myIrc.sendMessage(myUser,rpl004);
				myUser.setWelcomed();

			}
		}
		else
			myIrc.sendError(&myUser, NULL, ERR_NICKNAMEINUSE, myArgs[0]);

	}
	else
		myIrc.sendError(&myUser, NULL, ERR_NOTEXTTOSEND, "");
}

