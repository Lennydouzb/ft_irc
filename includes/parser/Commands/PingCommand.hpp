/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:43 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:33 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class PingCommand : public ACommand
{
    public:
        PingCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
