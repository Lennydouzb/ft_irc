#pragma once
#include <string>
#include "../User.hpp"

class ICommand
{
    public:
        ICommand();
        virtual void exec(std::string *params) = 0;
};