//
// Created by itamarq on 4/30/22.
//

#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

using namespace std;
namespace coup {
    Game::Game() {

    }

    string Game::turn() {
        return "";
    }

    string Game::winner() {
        return this->winnerName;
    }

    vector<string> Game::players() {
        vector<string> players;
        return players;
    }

    bool Game::addToGame(Player &player) {
        return true;
    }

    bool Game::isInTheGame(Player &player) {
        return true;
    }
}