/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:38:16 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:12:19 by ldesboui         ###   ########.fr       */
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
#include "../includes/parser/Parser.hpp"
#include "../includes/User.hpp"
#include "Channel.hpp"

class Irc
{
	private:
		std::string 	password;
		u_int16_t		port;
		int				sockfd;
		std::vector<Channel>		openedChannel;
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
		bool	checkExistingNick(std::string nick);
};

