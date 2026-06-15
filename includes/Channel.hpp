/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:37:07 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:08:07 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <vector>
#include <string>
#include "User.hpp"

class Channel 
{
	private:
		std::vector<User*>	operators;
		std::vector<User*>	users;
		std::string			name;
		std::string			topic;
		bool				isInviteOnly;
		size_t				userLimit;
		bool				restrictedTopic;
		std::string			password;

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
	Channel(User& theOperator);
	~Channel();
	void	addUser(User &anUser);
	void	removeUser(User &anUser);
	void	setPassword(std::string passwd);
	void	setRestrictedTopic(bool val);
	void	setName(const std::string &name);
	void	setTopic(const std::string &topic);
	void	setInviteOnly(bool val);
	void	setUserLimit(size_t limit);
	
	std::vector<User&>&	getOperators();
	std::vector<User&>&	getUsers();
	const std::string&	getName() const;
	const std::string&	getTopic() const;
	bool			getIsInviteOnly() const;
	size_t			getUserLimit() const;
	bool			isRestrictedTopic() const;
	const std::string&	getPassword() const;

	void	sendMessage(User &sender, std::string message);
};
