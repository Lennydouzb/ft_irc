/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CapCommand.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:25 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:19 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser/Commands/CapCommand.hpp"
#include "../../../includes/Irc.hpp"
#include "../../../includes/User.hpp"

CapCommand::CapCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc)
{
}

void CapCommand::exec()
{
    // we dont do anything but it might be a future implementation
    int a;
    (void)a;
}

