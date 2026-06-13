/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CapCommand.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:04:50 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:05:52 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class CapCommand : public ACommand
{
    public:
        CapCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
