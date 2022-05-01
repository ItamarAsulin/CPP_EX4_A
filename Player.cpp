//
// Created by itamarq on 4/30/22.
//

#include "Player.hpp"
namespace coup {
    Player::Player() {

    }

    void Player::setName(string const &playerName) {

    }

    string Player::getName() {
        return this->name;
    }

    void Player::setRoleType(Character role) {

    }

    Character Player::getRoleType() {
        return this->roleType;
    }

    bool Player::income() {
        this->coinsNum++;
        return true;
    }

    bool Player::foreign_aid() {
        this->coinsNum += 2;
        return true;
    }

    bool Player::coup(Player &player) {
        return true;
    }

    string Player::role() {
        return "";
    }

    int Player::coins() {
        return true;
    }

    bool Player::isForeignAidBlockable() {
        return true;
    }

    void Player::setCoins(int numOfCoins) {

    }

    bool Player::isAlive(){
        return true;
    }
}