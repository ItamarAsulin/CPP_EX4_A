//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_GAME_HPP
#define EX4_A_GAME_HPP

#include <iostream>
#include <vector>
#include "Player.hpp"

using namespace std;
namespace coup {
    class Player;
    class Game {
    protected:
        vector<Player *> playersArrays;
        uint turnNum;
        Player *currentPlayer;
        string winnerName;
        bool isOver;
        uint position;

    public:
        Game();

        string turn();

        string winner();

        vector<string> players();

        bool isInTheGame(Player &player);

        bool addToGame(Player &player);
    };
}


#endif //EX4_A_GAME_HPP
