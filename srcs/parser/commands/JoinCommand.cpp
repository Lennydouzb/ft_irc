/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:28 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 23:53:51 by ldesboui         ###   ########.fr       */
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
	{
		myIrc.sendError(&myUser, NULL, ERR_NEEDMOREPARAMS, "");
		return ;
	}
	if (this->myUser.isUserReady())
	{
		if (myIrc.channelExist(myArgs[0]))
		{
			Channel& myChannel = myIrc.getChannel(myArgs[0]);
			if (myChannel.getIsInviteOnly() && !myChannel.isUserInvited(myUser))
			{

				myIrc.sendError(&myUser, NULL, ERR_INVITEONLYCHAN, "");
				return;
			}
			std::string passwd;
			if (myArgs.size() == 2)
				passwd = myArgs[1];
			else
				passwd = "";
			if (!myChannel.checkPassword(passwd))
			{
				myIrc.sendError(&myUser, NULL, ERR_BADCHANNELKEY, "");
				return ;
			}
			if (myChannel.getUserLimit() >= myChannel.getUsers().size())
			{
				myIrc.sendError(&myUser, NULL, ERR_CHANNELISFULL, "");
				return ;
			}
			std::string joinMsg = myUser.getPrefix() + "JOIN :"+ myChannel.getName() +"\r\n";
			myChannel.addUser(myUser);
			std::vector<User*>& users = myChannel.getUsers();
			for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
			{
				send((*it)->getSocket(), joinMsg.c_str(), joinMsg.length(), 0);
			}
			std::string nameList = "";
			for (size_t i = 0; i < users.size(); ++i)
			{
				if (myChannel.isUserOp(*(users[i]))) 
					nameList += "@";
					
				nameList += users[i]->getNickname() + " ";
			}
			myIrc.sendMessage(myUser, "353 " + myUser.getNickname() + " = " + myChannel.getName() + " :" + nameList);
			myIrc.sendMessage(myUser, "366 " + myUser.getNickname() + " " + myChannel.getName() + " :End of /NAMES list.");
		}
		else
		{
			std::string name = myArgs[0].substr(1, myArgs[0].length());
			Channel* aChannel = new Channel(myUser, name); 
			myIrc.addChannel(*aChannel);
			std::string joinMsg = myUser.getPrefix() + "JOIN :" + name + "\r\n";
  			send(myUser.getSocket(), joinMsg.c_str(), joinMsg.length(), 0);
			std::string namreply = "353 " + myUser.getNickname() + " = " + myArgs[0] + " :@" + myUser.getNickname();
			myIrc.sendMessage(myUser, namreply);
			std::string endofnames = "366 " + myUser.getNickname() + " " + myArgs[0] + " :End of /NAMES list.";
			myIrc.sendMessage(myUser, endofnames);
		}
	}
	else
		myIrc.sendError(&myUser, NULL, ERR_NOTREGISTERED, "");

}

