/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:52 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:38:55 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
#include "../../Irc.hpp"
#include "../../User.hpp"

class PrivmsgCommand : public ACommand
{
    public:
        PrivmsgCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
