/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:39:11 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:48 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class UserCommand : public ACommand
{
    public:
        UserCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
