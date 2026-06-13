/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NickCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:01 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:42 by ldesboui         ###   ########.fr       */
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
