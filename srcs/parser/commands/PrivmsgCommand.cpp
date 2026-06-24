/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:35 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 17:59:37 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/PrivmsgCommand.hpp"
#include "../../../includes/User.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/Channel.hpp"

PrivmsgCommand::PrivmsgCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void PrivmsgCommand::exec()
{
	if (myUser.isUserReady())
	{
		if (myArgs.size() == 2)
		{
			if (myArgs[1].size() == 1)
			{
				myIrc.sendError(&myUser, NULL, NULL, ERR_NOTEXTTOSEND, "");
				return ;
			}
			std::string prefix = myUser.getPrefix();
			if (*(myArgs[0].begin()) == '#')
			{
				if (myIrc.channelExist(myArgs[0]))
				{
					std::string message = prefix + "PRIVMSG #"  + myArgs[0] + " :" + myArgs[1];
					Channel& myChannel = myIrc.getChannel(myArgs[0]);
					if (myChannel.isUserIn(myUser))
						myIrc.sendMessage(myUser, myChannel, message);
					else
						myIrc.sendError(&myUser, NULL, NULL, ERR_CANNOTSENDTOCHAN, "");
				}
				else
					myIrc.sendError(&myUser, NULL, NULL, ERR_NOSUCHCHANNEL, myArgs[0]);
			}
			else
			{
				if (myIrc.checkExistingNick(myArgs[0]))
				{
					std::string message = prefix + "PRIVMSG "  + myArgs[0] + " :" + myArgs[1];
					User& receiver = myIrc.getUser(myArgs[0]);
					myIrc.sendMessage(myUser, receiver, message);
				}
				else
					myIrc.sendError(&myUser, NULL, NULL, ERR_NOSUCHNICK, myArgs[0]);
			}
		}
		else
		{
			if (myArgs.size() == 1)
			{
				if (myArgs[0][0] == ':')
					myIrc.sendError(&myUser, NULL, NULL, ERR_NORECIPIENT, "PRIVMSG");
				else
					myIrc.sendError(&myUser, NULL, NULL, ERR_NOTEXTTOSEND, "");
			}
		}
	}
	else
		myIrc.sendError(&myUser, NULL, NULL, ERR_NOTREGISTERED, "");
}

