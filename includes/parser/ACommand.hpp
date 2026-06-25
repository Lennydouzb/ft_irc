/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:09:18 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 16:51:01 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <vector>

class Irc;
class User;

class ACommand
{
    protected:
        std::vector<std::string> myArgs;
        Irc&                     myIrc;
        User&                    myUser;
    public:
        ACommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
		virtual ~ACommand();
        virtual void exec() = 0;
};
