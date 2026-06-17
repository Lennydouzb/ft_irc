/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:29 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:48:05 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/ModeCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"
#include "../../../includes/Channel.hpp"

ModeCommand::ModeCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{

}

void ModeCommand::exec()
{

}

