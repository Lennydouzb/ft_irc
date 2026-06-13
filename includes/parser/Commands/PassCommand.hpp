/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:04 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:38 by ldesboui         ###   ########.fr       */
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
