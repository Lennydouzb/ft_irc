#include "../../includes/parser/Parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

void Parser::exec(std::string *params)
{
    (void)params;
}

ICommand* Parser::getInstance(std::string command)
{

}

void Parser::parse(User &user, std::string arg)
{
    std::vector<std::string> args = split(arg);
    std::string *commands = {"NICK","PASS","JOIN","CAP","QUIT","USER","PING","PRIVMSG","","","",}
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
    return (args);
}
