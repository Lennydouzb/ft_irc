/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:26:54 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/09 14:15:22 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
class Irc;
class User
{
	private:
		std::string nickname;
		std::string username;
		int			socket;
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

		User(int fd, std::string nickname, std::string username);
		~User();
		static void	tryConnection(Irc &anIrc, uint16_t port, std::string password);
}
