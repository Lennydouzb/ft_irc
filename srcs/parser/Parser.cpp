/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:26:33 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/25 20:40:33 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser/Parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

ACommand* Parser::getInstance(std::string command, std::vector<std::string> args, User& anUser, Irc& anIrc)
{
    std::string commands[11] = {"NICK","PASS","JOIN","CAP","QUIT","USER","PING","PRIVMSG","TOPIC","MODE", "KICK"};
    int aCommand = 0;
    while (aCommand < 11)
    {
        if (commands[aCommand] == command)
            break;
        ++aCommand;
    }
    switch (aCommand)
    {
        case (0):
            return new NickCommand(args, anUser, anIrc);
            break;
        case (1):
            return new PassCommand(args, anUser, anIrc);
            break;
        case (2):
            return new JoinCommand(args, anUser, anIrc);
            break;
        case (3):
            return new CapCommand(args, anUser, anIrc);
            break;
        case (4):
            return new QuitCommand(args, anUser, anIrc);
            break;
        case (5):
            return new UserCommand(args, anUser, anIrc);
            break;
        case (6):
            return new PingCommand(args, anUser, anIrc);
            break;
        case (7):
            return new PrivmsgCommand(args, anUser, anIrc);
            break;
        case (8):
            return new TopicCommand(args, anUser, anIrc);
            break;
        case (9):
            return new ModeCommand(args, anUser, anIrc);
            break;
        case (10):
            return new KickCommand(args, anUser, anIrc);
        default:
            return NULL;
    }
}

void Parser::parse(User &user, std::string arg, Irc &anIrc)
{
    std::vector<std::string> args = split(arg);
    std::string command = args[0];
    args.erase(args.begin());
    ACommand *myCommand = this->getInstance(command, args, user, anIrc);
	if (myCommand)
	{
		myCommand->exec();
		delete myCommand;
	}
}
std::vector<std::string> split(std::string message)
{
    std::vector<std::string> args;
    std::istringstream      iss(message);
    std::string             tmp;
    while (iss >> tmp)
    {
        if (tmp[0] == ':')
        {
            std::string end;
            std::getline(iss, end);
            args.push_back(tmp.substr(1) + end);
            break;
        }
        else
            args.push_back(tmp);
    }
	std::string& last = args.back();
    if (!last.empty() && last[last.size() - 1] == '\r')
        last.erase(last.size() - 1);
    return (args);
}
