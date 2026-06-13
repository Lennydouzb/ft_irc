#include "../../includes/parser/ACommand.hpp"

ACommand::ACommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : myIrc(anIrc), myUser(anUser)
{
    this->myArgs = args;
}

void exec(std::vector<std::string> params);