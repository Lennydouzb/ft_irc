/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:28 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/16 18:03:41 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/JoinCommand.hpp"

JoinCommand::JoinCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc){}

void JoinCommand::exec()
{
	if (myArgs.size() < 1)
		return;
	if (this->myUser.getIsPasswordVerified())
	{
		if (myIrc.channelExist(myArgs[0]))
		{
			Channel& myChannel = myIrc.getChannel(myArgs[0]);
			if (myChannel.getIsInviteOnly())
			{
				if (myChannel.isUserInvited(myUser))
				{
					std::string passwd;
					if (myArgs.size() == 2)
						passwd = myArgs[1];
					else
						passwd = "";
					if (myChannel.checkPassword(passwd))
					{
						myChannel.addUser(myUser);
					}
				}
			}
		}
		else
		{
			Channel* aChannel = new Channel(myUser, myArgs[0]); 
			myIrc.addChannel(*aChannel);
		}
	}
}

