/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:39:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/17 10:46:44 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"

class TopicCommand : public ACommand
{
    public:
        TopicCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
