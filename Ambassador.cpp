//
// Created by itamarq on 4/30/22.
//

#include "Ambassador.hpp"
#include "Player.hpp"
#include <iostream>
#include "Game.hpp"
namespace coup {
    Ambassador::Ambassador(coup::Game &game, string const name) {

    }

    bool Ambassador::transfer(Player &playerFrom, Player &playerTo) {
        return true;
    }

    bool Ambassador::block(Player &captain) {
        return true;
    }
}