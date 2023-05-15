//
// Created by beni on 5/15/23.
//
#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;

TEST_CASE("Test Cowboy Class") {
    // Create a new Cowboy
    Point cowboy_pos(10, 19);
    Cowboy Lucky_Luke("Lucky Luke", cowboy_pos);
    // Check if 'Lucky Luke' was initialized correctly
    CHECK(Lucky_Luke.getName() == "Lucky Luke");
    CHECK_EQ(Lucky_Luke.getLife(), 110);
    CHECK(Lucky_Luke.isAlive());
    CHECK(Lucky_Luke.hasbullets());
    // Create another Cowboy
    Point cowboy_pos2(1, 1);
    Cowboy yuval("yuval tibi", cowboy_pos2);
    // Lucky Luke shoots at yuval
    Lucky_Luke.shoot(&yuval);
    // Check yuval's life after shooting
    CHECK_EQ(yuval.getLife(), 100);
    // Lucky Luke shoots until he has no bullets left
    for (int i = 0; i < 5; i++) {
        Lucky_Luke.shoot(&yuval);
    }
    // Check that Lucky Luke has no bullets left
    CHECK_FALSE(Lucky_Luke.hasbullets());
    // Check yuval's life after being shot multiple times
    CHECK_EQ(yuval.getLife(), 50);
    // Check if Lucky Luke have bullets after reloading
    Lucky_Luke.reload();
    CHECK(Lucky_Luke.hasbullets());
}

TEST_CASE("Test Ninja Class") {
//create new ninjas
    Point Goten_pos(10, 19);
    Point Kakaroto_pos(10, 19);
    Point HattoriHanzo_pos(40, 50);
    YoungNinja Goten("Goten", Goten_pos);
    TrainedNinja Kakaroto("Kakaroto", Kakaroto_pos);
    OldNinja Hattori_Hanzo("Hattori Hanzo", HattoriHanzo_pos);
// Check if the ninjas was initialized correctly
    CHECK(Goten.getName() == "Goten");
    CHECK_EQ(Goten.getLife(), 100);
    CHECK_EQ(Goten.getSpeed(), 14);
    CHECK(Kakaroto.getName() == "Kakaroto");
    CHECK_EQ(Kakaroto.getLife(), 120);
    CHECK_EQ(Kakaroto.getSpeed(), 12);
    CHECK(Hattori_Hanzo.getName() == "Hattori Hanzo");
    CHECK_EQ(Hattori_Hanzo.getLife(), 150);
    CHECK_EQ(Hattori_Hanzo.getSpeed(), 8);
//Check Goten's life after being slashed
    Kakaroto.slash(&Goten);
    CHECK_EQ(Goten.getLife(), 60);
//Check Kakaroto's life after being slashed
    Hattori_Hanzo.slash(&Kakaroto);
    CHECK_EQ(Kakaroto.getLife(), 120);
}

TEST_CASE("Test Team Class") {
    // Create some ninjas and cowboys
    Point beni_pos(10, 19);
    Point yuval_pos(1, 1);
    Point dani_pos(1, 1);
    Cowboy beni_tibi("beni tibi", beni_pos);
    YoungNinja yuval_tibi("yuval tibi", yuval_pos);
    Cowboy daniel_tibi("daniel tibi", dani_pos);
    // Create a team with "beni tibi" as the leader
    Team team(&beni_tibi);
    // Add members to the team
    team.add(&yuval_tibi);
    CHECK_EQ(team.stillAlive(), 2);
    for (int i = 0; i < 11; i++) {
        if (!daniel_tibi.hasbullets()) {
            daniel_tibi.reload();
        }
        daniel_tibi.shoot(&beni_tibi);
    }
    CHECK_EQ(team.stillAlive(), 1);
}




