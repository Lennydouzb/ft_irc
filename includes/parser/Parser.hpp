#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "../User.hpp"
#include "ICommand.hpp"

class Parser
{
    private:


    public:
        ~Parser();
        Parser();
        static void parse(User& user, std::string message);
        static ICommand* getInstance(std::string command);  
};
std::vector<std::string> split(std::string message);