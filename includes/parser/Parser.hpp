/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:09:22 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 16:51:06 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "../User.hpp"
#include "ACommand.hpp"
#include "Commands/CapCommand.hpp"
#include "Commands/JoinCommand.hpp"
#include "Commands/ModeCommand.hpp"
#include "Commands/NickCommand.hpp"
#include "Commands/PassCommand.hpp"
#include "Commands/PingCommand.hpp"
#include "Commands/QuitCommand.hpp"
#include "Commands/TopicCommand.hpp"
#include "Commands/UserCommand.hpp"
#include "Commands/PrivmsgCommand.hpp"
#include "Commands/KickCommand.hpp"


class Parser
{
    public:
        ~Parser();
        Parser();
        void parse(User& user, std::string message, Irc& anIrc);
		ACommand*	getInstance(std::string command, std::vector<std::string> args, User& anUser, Irc& anIrc);
};
std::vector<std::string> split(std::string message);
