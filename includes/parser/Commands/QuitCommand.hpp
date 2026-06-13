/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:11 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:32 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
class QuitCommand : public ACommand
{
    public:
        QuitCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
