/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:37 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/26 14:26:42 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/TopicCommand.hpp"
#include "../../../includes/User.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/Channel.hpp"
#include <string>

TopicCommand::TopicCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void TopicCommand::exec()
{
	if (myUser.isUserReady())
	{
		if (myArgs.size() == 2)
		{
			//case of modification
			if (myIrc.channelExist(myArgs[0]))
			{
				Channel &myChannel = myIrc.getChannel(myArgs[0]);
				if (myChannel.isUserIn(myUser))
				{
					if (myChannel.isRestrictedTopic())
					{
						if (myChannel.isUserOp(myUser))
						{
							myChannel.setTopic(myArgs[1]);
							myIrc.sendMessage(myUser, myUser.getPrefix() + " TOPIC " + myChannel.getName() + " :" + myChannel.getTopic());
							myIrc.sendMessage(myUser, myChannel, myUser.getPrefix() + " TOPIC " + myChannel.getName() + " :" + myChannel.getTopic());
						}
						else
							myIrc.sendError(&myUser, &myChannel, ERR_CHANOPRIVSNEEDED, "");
					}
					else
					{
						if (myChannel.isUserIn(myUser))
						{
							myChannel.setTopic(myArgs[1]);
							myIrc.sendMessage(myUser, myUser.getPrefix() + " TOPIC " + myChannel.getName() + " :" + myChannel.getTopic());
							myIrc.sendMessage(myUser, myChannel, myUser.getPrefix() + " TOPIC " + myChannel.getName() + " :" + myChannel.getTopic());
						}
						else
							myIrc.sendError(&myUser, &myChannel, ERR_NOTONCHANNEL, "");
					}
				}
				else
					myIrc.sendError(&myUser, &myChannel, ERR_NOTONCHANNEL, "");
			}
			else
				myIrc.sendError(&myUser, NULL, ERR_NOSUCHCHANNEL, myArgs[0]);
		}
		else
		{
			//case of topic check  without modification
			if (myArgs.size() == 1)
			{
				if (myArgs[0][0] == ':')
				{
					myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "TOPIC");
					return;	
				}
				else
				{
					if (myIrc.channelExist(myArgs[0]))
					{
						Channel &myChannel = myIrc.getChannel(myArgs[0]);
						if (myChannel.isUserIn(myUser))
						{
							std::string topic = myChannel.getTopic();
							if (topic.empty())
								myIrc.sendMessage(myUser, myIrc.getPrefix() + " 331 "+ myUser.getNickname() + " " + myChannel.getName() + " :Topic is not set");
							else
								myIrc.sendMessage(myUser, myIrc.getPrefix() + " 332 "+ myUser.getNickname() + " " + myChannel.getName() + " :" + topic);
						}
						else
							myIrc.sendError(&myUser, &myChannel, ERR_NOTONCHANNEL, "");
					}
					else
						myIrc.sendError(&myUser, NULL, ERR_NOSUCHCHANNEL, myArgs[0]);
				}
			}
			else
				myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "TOPIC");
		}
	}
	else
		myIrc.sendError(&myUser, NULL, ERR_NOTREGISTERED, "");
}

