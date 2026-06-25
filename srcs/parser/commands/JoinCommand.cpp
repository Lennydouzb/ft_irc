/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:28 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 20:51:26 by ldesboui         ###   ########.fr       */
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
		if (myArgs[0].empty() || myArgs[0][0] != '#')
		{
			myIrc.sendError(&myUser, NULL, ERR_NOSUCHCHANNEL, myArgs[0]);
			return;
		}
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
				myIrc.sendError(&myUser, &myChannel, ERR_BADCHANNELKEY, "");
				return ;
			}
			if (myChannel.getUserLimit() != 0 && myChannel.getUserLimit() <= myChannel.getUsers().size())
			{
				myIrc.sendError(&myUser, &myChannel, ERR_CHANNELISFULL, "");
				return ;
			}
			std::string joinMsg = myUser.getPrefix() + "JOIN :"+ myChannel.getName() +"\r\n";
			myChannel.addUser(myUser);
			std::vector<User*>& users = myChannel.getUsers();
			for (std::vector<User*>::iterator it = users.begin(); it != users.end(); ++it)
			{
				(*it)->addBuffer(joinMsg);
			}
			std::string nameList = "";
			for (size_t i = 0; i < users.size(); ++i)
			{
				if (myChannel.isUserOp(*(users[i]))) 
					nameList += "@";
					
				nameList += users[i]->getNickname() + " ";
			}
			myIrc.sendMessage(myUser, myIrc.getPrefix() +" 353 " + myUser.getNickname() + " = " + myChannel.getName() + " :" + nameList);
			myIrc.sendMessage(myUser, myIrc.getPrefix() +" 366 " + myUser.getNickname() + " " + myChannel.getName() + " :End of /NAMES list.");
		}
		else
		{
			Channel* aChannel = new Channel(myUser, myArgs[0]); 
			myIrc.addChannel(*aChannel);
			std::string joinMsg = myUser.getPrefix() + "JOIN :" + myArgs[0] + "\r\n";
  			myIrc.sendMessage(myUser, joinMsg);
			std::string namreply = myIrc.getPrefix()  +" 353 " + myUser.getNickname() + " = " + myArgs[0] + " :@" + myUser.getNickname();
			myIrc.sendMessage(myUser, namreply);
			std::string endofnames = myIrc.getPrefix() + " 366 " + myUser.getNickname() + " " + myArgs[0] + " :End of /NAMES list.";
			myIrc.sendMessage(myUser, endofnames);
		}
	}
	else
		myIrc.sendError(&myUser, NULL, ERR_NOTREGISTERED, "");

}

