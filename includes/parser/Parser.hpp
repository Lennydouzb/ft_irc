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


class Parser
{
    private:


    public:
        ~Parser();
        Parser();
        static void parse(User& user, std::string message, Irc& anIrc);
        static ACommand* getInstance(std::string command, std::vector<std::string> args);
};
std::vector<std::string> split(std::string message);