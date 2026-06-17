/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:25:43 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:50:07 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser/ACommand.hpp"

ACommand::ACommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : myIrc(anIrc), myUser(anUser)
{
    this->myArgs = args;
}
