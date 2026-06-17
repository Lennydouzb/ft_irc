/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:16 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class JoinCommand : public ACommand
{
    public:
        JoinCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
