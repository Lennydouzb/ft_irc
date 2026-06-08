/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Except.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:21:45 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/08 11:20:40 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <string>

	class TheException: public std::exception
	{
	private:
		std::string message;
	public:
		~TheException() throw();
		TheException(std::string message);
		const char *what() const throw(); 
	};

