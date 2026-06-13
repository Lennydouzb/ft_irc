/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:17 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:15 by ldesboui         ###   ########.fr       */
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
