/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:32 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/16 14:13:27 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/PassCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"
PassCommand::PassCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void PassCommand::exec()
{
    if (!myUser.getIsPasswordVerified())
    {
        if (myIrc.verifiyPass(this->myArgs[0]))
		{
            myUser.verifyPassword();
			myIrc.addUser(myUser);
		}
    }
}

