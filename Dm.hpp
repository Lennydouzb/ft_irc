/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dm.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:42:25 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/08 11:22:55 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include "Except.hpp"

class Dm
{
class TheException: public std::exception
	{
	private:
		std::string message;
	public:
		~TheException() throw();
		TheException(std::string message);
		const char *what() const throw(); 
	};

};
