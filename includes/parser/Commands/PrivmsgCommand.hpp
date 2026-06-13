/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivmsgCommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:09 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:04 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
class PrivmsgCommand : public ACommand
{
    public:
        PrivmsgCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
