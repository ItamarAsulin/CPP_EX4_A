//
// Created by itamarq on 4/30/22.
//

#include "Assassin.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    Assassin::Assassin(coup::Game &game, string const name) {

    }

    bool Assassin::assassinate(Player &target) {
        return true;
    }

    bool Assassin::isBlockable() {
        return true;
    }
}