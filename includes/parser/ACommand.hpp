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
        virtual void exec() = 0;
};