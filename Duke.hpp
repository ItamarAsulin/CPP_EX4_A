//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_DUKE_HPP
#define EX4_A_DUKE_HPP
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    class Duke : public Player {
    protected:
        coup::Game *game;
    public:
        Duke(coup::Game &game, string const name);

        bool tax();

        bool block(Player &player);
    };

}
#endif //EX4_A_DUKE_HPP
