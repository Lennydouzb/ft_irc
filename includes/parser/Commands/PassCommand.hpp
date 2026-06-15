/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:35 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:38:40 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
#include "../../Irc.hpp"
#include "../../User.hpp"

class PassCommand : public ACommand
{
    public:
        PassCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
