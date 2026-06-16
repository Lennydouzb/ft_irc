/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:30:16 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/16 17:05:59 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/KickCommand.hpp"

KickCommand::KickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc){}

void KickCommand::exec()
{
    if (this->myUser.getIsPasswordVerified())
    {
        if (myIrc.channelExist(myArgs[0]))
        {
            Channel& myChannel = myIrc.getChannel(myArgs[0]);
			if (myChannel.isUserOp(myUser))
			{
				if(myIrc.checkExistingNick(myArgs[1]))
				{
					User &anUser = myIrc.getUser(myArgs[1]);
					if (myChannel.isUserOp(myUser))
					{
						std::string reason = "";
						if (!myArgs[3].empty())
							reason = myArgs[3];
						myChannel.removeUser(anUser, reason);
					}
				}
			}
        }
    }
}
