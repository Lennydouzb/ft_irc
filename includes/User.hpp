/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:26:54 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/24 17:51:17 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <poll.h>

class Irc;
class User
{
	private:
		std::string 	nickname;
		std::string 	username;
		std::string		realname;
		int				socket;
		bool 			isPasswordVerified;
		struct pollfd	pollfd;

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
		void			setpollfd(struct pollfd pollfd);
		struct pollfd	getpollfd();
		int				getSocket();
		std::string		getNickname();
		std::string		getUsername();
		bool			getIsPasswordVerified();
		bool			isUserReady();
		void			setNickname(std::string nickname);
		void			setUsername(std::string username);
		void			verifyPassword();
		std::string		getRealname();
		void			setRealname(std::string realname);
		std::string		getPrefix() const;
		bool			isNickUsable(std::string nick) const;
};
