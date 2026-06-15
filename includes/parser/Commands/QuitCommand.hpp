/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:58 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:39:04 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
#include "../../Irc.hpp"
#include "../../User.hpp"

class QuitCommand : public ACommand
{
    public:
        QuitCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
