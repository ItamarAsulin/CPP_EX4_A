//
// Created by itamarq on 5/1/22.
//
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "doctest.h"
#include "Characters.hpp"

#include <exception>
#include <iostream>

using namespace coup;
using namespace std;

TEST_CASE ("General Player Tests") {
    Game game{};
    Duke duke{game, "Moshe"};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    Captain captain{game, "Reut"};
    Contessa contessa{game, "Gilad"};
    //checking to see that the roles are set correctly.
            CHECK_EQ(duke.getRoleType(), Character::DUKE);
            CHECK_EQ(assassin.getRoleType(), Character::ASSASSIN);
            CHECK_EQ(ambassador.getRoleType(), Character::AMBASSADOR);
            CHECK_EQ(captain.getRoleType(), Character::CAPTAIN);
            CHECK_EQ(contessa.getRoleType(), Character::CONTESSA);
    //checking to see that all the coins are set properly.
            CHECK_EQ(0, duke.coins());
            CHECK_EQ(0, assassin.coins());
            CHECK_EQ(0, ambassador.coins());
            CHECK_EQ(0, captain.coins());
            CHECK_EQ(0, contessa.coins());
    duke.income();
    //checking to see that income does increase the coins by 1.
            CHECK_EQ(1, duke.income());
    assassin.foreign_aid();
    //checking to see that foreign aid increase coins by 2.
            CHECK_EQ(2, assassin.coins());
    //checking to see that an exception is thrown when trying to coup with less than 7 coins.
    for (int i = 0; i < 7; ++i) {
        ambassador.setCoins(i);
                CHECK_THROWS(ambassador.coup(assassin));
    }
    ambassador.setCoins(10);
    //checking that income and foreign aid throw exception when the player has 10 coins.
            CHECK_THROWS(ambassador.income());
            CHECK_THROWS(ambassador.foreign_aid());
    //checking that an exception is not thrown when the player has 10 coins.
            CHECK_NOTHROW(ambassador.coup(assassin));
    //checking that coup does use 7 coins.
            CHECK_EQ(3, ambassador.coins());
    //checking that coup kills the target player.
            CHECK_FALSE(assassin.isAlive());
}

TEST_CASE ("Ambassador Tests") {
    Game game{};
    Duke duke{game, "Moshe"};
    Ambassador ambassador{game, "Meirav"};
    Assassin assassin{game, "Yossi"};
    Captain captain{game, "Reut"};
    Contessa contessa{game, "Gilad"};
    duke.income();
    //checking that an exception is thrown when trying to transfer from player with no coins.
            CHECK_THROWS(ambassador.transfer(assassin, duke));
    assassin.setCoins(2);
    //checking that transfer is working when player has enough coins.
            CHECK_NOTHROW(ambassador.transfer(assassin, captain));
    //checking that the coins do transfer from player to player.
            CHECK_EQ(assassin.coins(), captain.coins());
    //checking that an exception is thrown when trying to block captain
    //that did not steal or from role different from captain.
            CHECK_THROWS(ambassador.block(captain));
            CHECK_THROWS(ambassador.block(duke));
            CHECK_THROWS(ambassador.block(assassin));
            CHECK_THROWS(ambassador.block(ambassador));
            CHECK_THROWS(ambassador.block(contessa));
    //checking that the ambassador does block, and that coins transfer back to player they are stolen from.
            CHECK_EQ(assassin.coins(), 2);
            CHECK_EQ(captain.coins(), 0);
    captain.steal(assassin);
            CHECK_EQ(assassin.coins(), 0);
            CHECK_EQ(captain.coins(), 2);
            CHECK_NOTHROW(ambassador.block(captain));
            CHECK_EQ(assassin.coins(), 2);
            CHECK_EQ(captain.coins(), 0);

    contessa.income();
    duke.income();
    //checking that an exception is thrown when trying to transfer with 10 coins.
    ambassador.setCoins(10);
            CHECK_THROWS(ambassador.transfer(duke, assassin));
}

TEST_CASE ("Assassin Tests") {
    Game game{};
    Duke duke{game, "Moshe"};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    //checking that assassin can't assassinate with less than 3 coins.
    duke.income();
    for (int i = 0; i < 2; ++i) {
        assassin.setCoins(i);
                CHECK_THROWS(assassin.assassinate(duke));
    }
    //checking that assassin does assassinate with 3 coins, that coins count update and that the target player is killed.
    assassin.setCoins(3);
            CHECK(duke.isAlive());
            CHECK_NOTHROW(assassin.assassinate(duke));
            CHECK_FALSE(duke.isAlive());
            CHECK_EQ(assassin.coins(), 0);
    ambassador.income();
    //making sure that assassin can assassinate with 10 coins.
    assassin.setCoins(10);
            CHECK_NOTHROW(assassin.assassinate(ambassador));
}

TEST_CASE ("Captain Tests") {
    Game game{};
    Duke duke{game, "Moshe"};
    Captain captain1{game, "Reut"};
    Captain captain2{game, "Fredi"};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    Contessa contessa{game, "Gilad"};

    duke.income();
    //checking that captain can't steal from a player with less than 2 coins.
            CHECK_THROWS(captain1.steal(contessa));
    //checking that captain can't block another captain that did not steal, or from a role that is not captain.
            CHECK_THROWS(captain1.block(captain2));
            CHECK_THROWS(captain1.block(duke));
            CHECK_THROWS(captain1.block(assassin));
            CHECK_THROWS(captain1.block(ambassador));
            CHECK_THROWS(captain1.block(contessa));
    duke.setCoins(2);
    //checking that captain can steal from a player with 2 coins, that they do transfer and that another captain can block the stealing.
            CHECK_NOTHROW(captain1.steal(duke));
            CHECK_EQ(duke.coins(), 0);
            CHECK_EQ(captain1.coins(), 2);
            CHECK_NOTHROW(captain2.block(captain1));
            CHECK_EQ(duke.coins(), 2);
            CHECK_EQ(captain1.coins(), 0);
    captain2.income();
    assassin.income();
    ambassador.income();
    contessa.income();
    duke.income();
    //checking that captain can't steal with 10 coins.
    captain1.setCoins(10);
            CHECK_THROWS(captain1.steal(duke));
}

TEST_CASE ("Contessa Tests") {
    Game game{};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    Captain captain{game, "Reut"};
    Contessa contessa{game, "Gilad"};
    Duke duke{game, "Moshe"};
    //checking that the contessa can't block an assassin that did not assassinate, or a different class.
    assassin.setCoins(10);
            CHECK(duke.isAlive());
            CHECK_THROWS(contessa.block(assassin));
            CHECK_THROWS(contessa.block(ambassador));
            CHECK_THROWS(contessa.block(captain));
            CHECK_THROWS(contessa.block(duke));
    //checking that the contessa can block assassination and that the player is revived.
    assassin.assassinate(duke);
            CHECK_FALSE(duke.isAlive());
            CHECK_NOTHROW(contessa.block(assassin));
            CHECK(duke.isAlive());
}

TEST_CASE ("Duke Tests") {
    Game game{};
    Duke duke{game, "Moshe"};
    Assassin assassin{game, "Yossi"};
    //checking that tax does get 3 coins.
            CHECK_EQ(duke.coins(), 0);
    duke.tax();
            CHECK_EQ(duke.coins(), 3);
    //checking that duke can't block a player that did not use foreign aid and that he does block a player who did.
            CHECK_EQ(assassin.coins(), 0);
            CHECK_THROWS(duke.block(assassin));
    assassin.foreign_aid();
            CHECK_EQ(assassin.coins(), 2);
    duke.block(assassin);
            CHECK_EQ(assassin.coins(), 0);
    //checking that duke can't tax with 10 coins.
    duke.setCoins(10);
            CHECK_THROWS(duke.tax());
}

TEST_CASE ("Game Tests") {
    Game game{};
    Duke duke{game, "Moshe"};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    Captain captain1{game, "Reut"};
    Captain captain2{game, "Fredi"};
    Contessa contessa{game, "Gilad"};
    //checking that the turns are going by order, and in cyclic manner.
            CHECK_EQ(game.turn(), duke.getName());
    duke.income();
            CHECK_EQ(game.turn(), assassin.getName());
    assassin.income();
            CHECK_EQ(game.turn(), ambassador.getName());
    ambassador.income();
            CHECK_EQ(game.turn(), captain1.getName());
    captain1.income();
            CHECK_EQ(game.turn(), captain2.getName());
    captain2.income();
            CHECK_EQ(game.turn(), contessa.getName());
    contessa.income();
            CHECK_EQ(game.turn(), duke.getName());
    //checking that a player can't play when it's not his turn.
            CHECK_THROWS(assassin.income());
            CHECK_THROWS(ambassador.income());
            CHECK_THROWS(captain1.income());
            CHECK_THROWS(contessa.income());
            CHECK_NOTHROW(duke.income());
    //checking that all roles can block out of their turns.
    assassin.foreign_aid();
            CHECK_NOTHROW(duke.block(assassin));
            CHECK_EQ(game.turn(), ambassador.getName());
    ambassador.foreign_aid();
    captain1.steal(ambassador);
            CHECK_NOTHROW(ambassador.block(captain1));
    duke.setCoins(5);
    captain2.steal(duke);
            CHECK_NOTHROW(captain1.block(captain2));
    contessa.income();
    duke.income();
    //checking that the players method returns only the active players and that contessa can block out of her turn.
    assassin.setCoins(3);
            CHECK(game.isInTheGame(ambassador));
    assassin.assassinate(ambassador);
            CHECK_FALSE(game.isInTheGame(ambassador));
    string killedAmbassador = ambassador.getName();
    vector<string> players = game.players();
    for (string playerName: players) {
                CHECK_FALSE(playerName == killedAmbassador);
    }
            CHECK_NOTHROW(contessa.block(assassin));
            CHECK_EQ(game.turn(), captain1.getName());
    bool isBackInTheGame = false;
    players = game.players();
    for (string playerName: players) {
        if (playerName == killedAmbassador) {
            isBackInTheGame = true;
        }
    }
            CHECK(isBackInTheGame);

}