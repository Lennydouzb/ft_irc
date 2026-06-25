/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:40 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 16:15:06 by ldesboui         ###   ########.fr       */
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
				if (myUser.isUserReady() && !myUser.getIsWelcomed())
				{
					std::string srvPrefix = myUser.getPrefix() + " ";
					std::string nick = myUser.getNickname();
					std::string rpl001 = srvPrefix + "001 " + nick + " :Welcome to the ft_irc Network, " + nick + "!" + myUser.getUsername() + "@127.0.0.1\r\n";
					std::string rpl002 = srvPrefix + "002 " + nick + " :Running on ft_irc\r\n";
					std::string rpl003 = srvPrefix + "003 " + nick + " :Greetings\r\n";
					std::string rpl004 = srvPrefix + "004 " + nick + " ft_irc\r\n";
					myIrc.sendMessage(myUser, rpl001);
					myIrc.sendMessage(myUser,rpl002);
					myIrc.sendMessage(myUser,rpl003);
					myIrc.sendMessage(myUser,rpl004);
					myUser.setWelcomed();
				}
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

