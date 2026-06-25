/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:30:16 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 16:03:01 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/KickCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"
#include "../../../includes/Channel.hpp"

KickCommand::KickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc){}

void KickCommand::exec()
{
	if (this->myUser.isUserReady())
	{
		if (myArgs.size() >= 2)
		{
			if (myIrc.channelExist(myArgs[0]))
			{
				Channel& myChannel = myIrc.getChannel(myArgs[0]);
				if (myChannel.isUserIn(myUser))
				{
					if (myChannel.isUserOp(myUser))
					{
						if(myIrc.checkExistingNick(myArgs[1]))
						{
							User &anUser = myIrc.getUser(myArgs[1]);
							std::string reason = "";
							std::string message = " KICK " + myChannel.getName() + " " + anUser.getNickname();
							if (myArgs.size() > 2 && !myArgs[2].empty())
								reason = myArgs[2];
							if (reason != "")
								message += " ";
							message = myUser.getPrefix() + message + reason;
							std::vector<User*>& users = myChannel.getUsers();
							for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
							{
									if (message.size() < 2 || message.substr(message.size() - 2) != "\r\n")
									{
										message += "\r\n";
									}
									(*it)->addBuffer(message);
							}
							myChannel.removeUser(anUser);	
						}
						else
							myIrc.sendError(&myUser, &myChannel, ERR_USERNOTINCHANNEL, myArgs[0]);
					}
					else
						myIrc.sendError(&myUser, &myChannel, ERR_CHANOPRIVSNEEDED, "");				}
				else
					myIrc.sendError(&myUser, &myChannel, ERR_NOTONCHANNEL, "");
			}
			else
				myIrc.sendError(&myUser, NULL, ERR_NOSUCHCHANNEL, myArgs[0]);
		}
		else
			myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "KICK");

	}
}
