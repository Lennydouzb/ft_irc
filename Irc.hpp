/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:38:16 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/09 14:22:10 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include "includes.hpp"

class Irc
{
	private:
		std::string password;
		uint16_t	port;
		int			sockfd;

		std::vector<Channel>	openedChannel;
		std::vector<Dm>			openedDm;
		std::vector<User>		activeUsers;
		std::vector<t_pollfd>	pollfds;
		bool					isRunning;
		void	startConnection();
		void	handleMessage(User &aUser, std::string message);
		void	handleDisconnection(User &aUser);

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
		void	run();
};
