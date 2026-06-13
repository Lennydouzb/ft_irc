/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:35 by ldesboui         ###   ########.fr       */
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
