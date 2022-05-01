//
// Created by itamarq on 4/30/22.
//

#include "Captain.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    Captain::Captain(coup::Game &game, string const name) {

    }

    bool Captain::steal(Player &target) {
        return true;
    }

    bool Captain::block(Player &player) {
        return true;
    }

    bool Captain::isBlockable() {
        return true;
    }
}