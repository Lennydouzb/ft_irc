/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CapCommand.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:20:22 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:11 by ldesboui         ###   ########.fr       */
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
