/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:38:16 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 17:44:09 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <vector>
#include <poll.h>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include "parser/Parser.hpp"
#include "User.hpp"
#include "parser/ACommand.hpp"
#include "Channel.hpp"

enum e_irc_error {
    ERR_NOSUCHNICK			= 401,
    ERR_NOSUCHCHANNEL      	= 403,
    ERR_CANNOTSENDTOCHAN   	= 404,
    ERR_NOORIGIN           	= 409,
    ERR_NORECIPIENT        	= 411,
    ERR_NOTEXTTOSEND       	= 412,
    ERR_NONICKNAMEGIVEN    	= 431,
    ERR_ERRONEUSNICKNAME   	= 432,
    ERR_NICKNAMEINUSE      	= 433,
    ERR_USERNOTINCHANNEL   	= 441,
    ERR_NOTONCHANNEL       	= 442,
	ERR_NOTREGISTERED		= 451,
    ERR_NEEDMOREPARAMS		= 461,
	ERR_ALREADYREGISTERED	= 462,
    ERR_CHANNELISFULL      	= 471,
    ERR_UNKNOWNMODE        	= 472,
    ERR_INVITEONLYCHAN     	= 473,
    ERR_BADCHANNELKEY      	= 475,
    ERR_CHANOPRIVSNEEDED   	= 482,
    ERR_UMODEUNKNOWNFLAG   	= 501,
    ERR_USERSDONTMATCH     	= 502
};
class Irc
{
	private:
		std::string 	password;
		u_int16_t		port;
		int				sockfd;
		std::vector<Channel*>		openedChannel;
		std::vector<User*>			Users;
		std::vector<std::string>	messages;
		Parser						Parser;
	public:
		class TheException: public std::exception
		{
			private:
				std::string message;
			public:
				~TheException() throw();
				TheException(std::string message);
				const char *what() const throw(); 
		};

		Irc(u_int16_t port, std::string password);
		~Irc();
		void	run();
		bool	verifiyPass(std::string passwd);
		void	addUser(User& anUser);
		void	addChannel(Channel& aChannel);
		bool	checkExistingNick(std::string nick);
		bool	channelExist(std::string name);
		User&		getUser(std::string nick);
		Channel&	getChannel(std::string);
		std::vector<Channel*>& getChannels();
		void	sendMessage(User &sender, User& receiver, std::string message);
		void	sendMessage(User &sender, Channel& receiver, std::string message);
		void	sendMessage(User& receiver, std::string message);
		void	sendError(User* sender, User* receiver, Channel* aChannel, int errType, std::string command);
		std::string	getPrefix() const;
};

