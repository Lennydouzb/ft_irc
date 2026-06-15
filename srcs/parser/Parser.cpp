#include "../../includes/parser/Parser.hpp"

Parser::Parser(){}

Parser::~Parser(){}

ACommand* Parser::getInstance(std::string command, std::vector<std::string> args);
{
    std::string commands[10] = {"NICK","PASS","JOIN","CAP","QUIT","USER","PING","PRIVMSG","TOPIC","MODE", "KICK"};
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
            return new NickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (1):
            return new PassCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (2):
            return new JoinCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (3):
            return new CapCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (4):
            return new QuitCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (5):
            return new UserCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (6):
            return new PingCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (7):
            return new PrivmsgCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (8):
            return new TopicCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (9):
            return new ModeCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
            break;
        case (10):
            return new KickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc)
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
