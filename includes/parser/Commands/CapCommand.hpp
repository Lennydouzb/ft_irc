#pragma once
#include "../ACommand.hpp"
#include "../../Irc.hpp"
#include "../../User.hpp"

class CapCommand : public ACommand
{
    public:
        CapCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
