/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:05:15 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/13 20:06:10 by ldesboui         ###   ########.fr       */
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
