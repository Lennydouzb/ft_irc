/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:37:07 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/26 13:09:58 by ldesboui         ###   ########.fr       */
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
		std::vector<User*>	invited;
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
	Channel(User& theOperator, std::string name);
	~Channel();
	void	addUser(User &anUser);
	void	removeUser(User &anUser);
	void	setPassword(std::string passwd);
	void	setRestrictedTopic(bool val);
	void	setName(const std::string &name);
	void	setTopic(const std::string topic);
	void	setInviteOnly(bool val);
	void	setUserLimit(size_t limit);
	bool	checkPassword(std::string passwd);
	
	std::vector<User*>&	getOperators();
	std::vector<User*>&	getUsers();
	const std::string&	getName() const;
	const std::string&	getTopic() const;
	bool			getIsInviteOnly() const;
	size_t			getUserLimit() const;
	bool			isRestrictedTopic() const;
	bool			isUserIn(User& anUser);
	bool			isUserOp(User& anUser);
	bool			isUserInvited(User& anUser);

};
