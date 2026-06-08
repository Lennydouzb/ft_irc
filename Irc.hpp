/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:38:16 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/08 11:20:56 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <vector>
#include <string>
#include "Channel.hpp"
#include "Dm.hpp"
#include "User.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Irc
{
	private:
		std::string password;
		uint16_t	port;
		int			sockfd;

		std::vector<Channel>	openedChannel;
		std::vector<Dm>			openedDm;
		std::vector<User>		activeUsers;
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

		Irc(uint16_t port, std::string password);
		~Irc();
		void	startConnection(User &aUser, uint16_t port, std::string password);
};
