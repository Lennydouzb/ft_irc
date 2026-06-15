/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:12 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:38:15 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
#include "../../Irc.hpp"
#include "../../User.hpp"

class KickCommand : public ACommand
{
    public:
        KickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
