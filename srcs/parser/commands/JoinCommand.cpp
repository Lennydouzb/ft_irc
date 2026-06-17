/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:28 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 13:18:05 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/JoinCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"
#include "../../../includes/Channel.hpp"

JoinCommand::JoinCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc){}

void JoinCommand::exec()
{
	if (myArgs.size() < 1)
		return;
	if (this->myUser.isUserReady())
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
						std::string joinMsg = ":"+myUser.getNickname()+"!"+myUser.getUsername()+"@127.0.0.1 JOIN "+ myChannel.getName() +"\r\n";
						myChannel.addUser(myUser);
						std::vector<User*>& users = myChannel.getUsers();
						for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
						{
							send((*it)->getSocket(), joinMsg.c_str(), joinMsg.length(), 0);
						}
					}
				}
			}
		}
		else
		{
			Channel* aChannel = new Channel(myUser, myArgs[0]); 
			myIrc.addChannel(*aChannel);
			std::string joinMsg = ":" + myUser.getNickname() + "!" + myUser.getUsername() + "@127.0.0.1 JOIN :" + myArgs[0] + "\r\n";
  			send(myUser.getSocket(), joinMsg.c_str(), joinMsg.length(), 0);
			std::string namreply = "353 " + myUser.getNickname() + " = " + myArgs[0] + " :@" + myUser.getNickname();
			myIrc.sendMessage(myUser, namreply);
			std::string endofnames = "366 " + myUser.getNickname() + " " + myArgs[0] + " :End of /NAMES list.";
			myIrc.sendMessage(myUser, endofnames);
		}
	}
}

