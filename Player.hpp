//
// Created by itamarq on 4/30/22.
//

#ifndef EX4_A_PLAYER_HPP
#define EX4_A_PLAYER_HPP
#include <iostream>
#include "Characters.hpp"
#include "Game.hpp"

using namespace std;
namespace coup {
    class Game;
    class Player {

    protected:
        string name;
        int coinsNum;
        Character roleType;
        bool foreignAidBlockable;
        bool alive;
        coup::Game *game;

    public:
        Player();

        void setName(string const &playerName);

        string getName();

        void setRoleType(Character role);

        Character getRoleType();

        void setCoins(int numOfCoins);

        bool income();

        bool foreign_aid();

        bool coup(Player &player);

        string role();

        int coins();

        bool isForeignAidBlockable();

        bool isAlive();
    };
}

#endif //EX4_A_PLAYER_HPP
