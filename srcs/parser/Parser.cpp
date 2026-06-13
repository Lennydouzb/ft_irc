#include "../../includes/parser/Parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

void Parser::exec(std::string *params)
{
    (void)params;
}

ACommand* Parser::getInstance(std::string command, std::vector<std::string> args)
{
    std::string commands[10] = {"NICK","PASS","JOIN","CAP","QUIT","USER","PING","PRIVMSG","TOPIC","MODE"};
    int aCommand = 0;
    while (aCommand < 10)
    {
        if (commands[aCommand] == command)
            break;
        ++aCommand;
    }
    switch (aCommand)
    {
        case (0):
            return new NickCommand(args);
            break;
        case (1):
            return new PassCommand(args);
            break;
        case (2):
            return new JoinCommand(args);
            break;
        case (3):
            return new CapCommand(args);
            break;
        case (4):
            return new QuitCommand(args);
            break;
        case (5):
            return new UserCommand(args);
            break;
        case (6):
            return new PingCommand(args);
            break;
        case (7):
            return new PrivmsgCommand(args);
            break;
        case (8):
            return new TopicCommand(args);
            break;
        case (9):
            return new ModeCommand(args);
            break;
        default:
            return NULL;
    }
}

void Parser::parse(User &user, std::string arg, Irc &anIrc)
{
    std::vector<std::string> args = split(arg);
    std::string command = args[0];
    args.erase(args.begin());
    ACommand *myCommand = Parser::getInstance(command, args);
    
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
