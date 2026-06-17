/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:26 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:26 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class NickCommand : public ACommand
{
    public:
        NickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
