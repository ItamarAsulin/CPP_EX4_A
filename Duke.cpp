//
// Created by itamarq on 4/30/22.
//

#include "Duke.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    Duke::Duke(coup::Game &game, string const name) {

    }

    bool Duke::tax() {
        return true;
    }

    bool Duke::block(Player &player) {
        return true;
    }
}