/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <ldesboui@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:39:06 by ldesboui          #+#    #+#             */
/*   Updated: 2026/06/15 13:39:08 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ACommand.hpp"
#include "../../Irc.hpp"
#include "../../User.hpp"

class TopicCommand : public ACommand
{
    public:
        TopicCommand(std::vector<std::string> args, User& anUser, Irc& anIrc);
        void exec();
};
