/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:38:58 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:49:32 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
#include <unistd.h>

class QuitCommand : public ACommand
{
    public:
        QuitCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
