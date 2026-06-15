#include "../../../includes/parser/Commands/KickCommand.hpp"

KickCommand::KickCommand(std::vector<std::string> args, User& anUser, Irc& anIrc) : ACommand(args, anUser, anIrc){}

void KickCommand::exec()
{
    if (this->myUser.getIsPasswordVerified())
    {
        
    }
}