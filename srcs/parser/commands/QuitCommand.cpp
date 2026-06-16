/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:09:44 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/16 18:15:53 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/QuitCommand.hpp"

QuitCommand::QuitCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void QuitCommand::exec()
{
	if (myUser.getIsPasswordVerified())
	{
		std::string message = "";
		if (!myArgs[0].empty())
			message = myArgs[0];
		std::vector<Channel>
		for ()
	}
	close (myUser.getSocket());
}

