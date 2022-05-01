//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_CPATAIN_HPP
#define EX4_A_CPATAIN_HPP
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    class Captain : public Player {
    protected:
        coup::Game *game;
        bool blockable;
    public:
        Captain(coup::Game &game, string const name);

        bool steal(Player &target);

        bool block(Player &player);

        bool isBlockable();
    };
}
#endif //EX4_A_CPATAIN_HPP
