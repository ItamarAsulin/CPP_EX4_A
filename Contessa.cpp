//
// Created by itamarq on 4/30/22.
//

#include "Contessa.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
#include "Assassin.hpp"
namespace coup {
    Contessa::Contessa(coup::Game &game, string const name) {

    }

    bool Contessa::block(Player &assassin) {
        return true;
    }
}