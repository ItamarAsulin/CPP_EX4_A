//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_CONTESSA_HPP
#define EX4_A_CONTESSA_HPP
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    class Contessa : public Player {
    protected:
        coup::Game *game;
    public:
        Contessa(coup::Game &game, string const name);

        bool block(Player &assassin);
    };

}
#endif //EX4_A_CONTESSA_HPP
