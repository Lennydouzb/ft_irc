/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:35 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:30 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class PassCommand : public ACommand
{
    public:
        PassCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
