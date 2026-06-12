/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:37:07 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/09 14:26:36 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <vector>
#include "User.hpp"

class Channel 
{
	private:
		std::vector<User*> operators;
		std::vector<User*> users;
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
	void sendMessage(User &sender, std::string message);
};
