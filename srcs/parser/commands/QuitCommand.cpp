/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:09:44 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 20:42:28 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/QuitCommand.hpp"
#include "../../../includes/User.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/Channel.hpp"

QuitCommand::QuitCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void QuitCommand::exec()
{
	std::string message = "";

	if (myArgs.size() > 0 && !myArgs[0].empty())
		message = myArgs[0];
	std::vector<Channel*> myChannels = myIrc.getChannels(); 
	for (std::vector<Channel*>::iterator it = myChannels.begin(); it != myChannels.end(); ++it)
	{
		if ((*it)->isUserIn(myUser))
			myIrc.sendMessage(myUser, **it, message);
	}
	if (myUser.getSocket() != -1)
	{
        myUser.closeSocket();
	}
}

