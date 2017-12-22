//
//  SuperHero.cpp
//  ws7_home-macOS
//
//  Created by Damian Murawiecki on 2017-12-09.
//  Copyright © 2017 Damian Murawiecki. All rights reserved.
//

#include <stdio.h>
#include "SuperHero.h"

namespace sict {
    SuperHero::SuperHero() : Hero() {
        bonus = -1;
        protection = -1;
    };
    SuperHero::SuperHero(const char* n, int h, int s, int b, int d) : Hero(n,h,s) {
        bonus = b;
        protection = d;
    }
    int SuperHero::attackStrength() const {
        return Hero::attackStrength() != -1 ? Hero::attackStrength() + bonus : 0;
    }
    int SuperHero::defend() const {
        return protection != -1 ? protection : 0;
    }
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
        SuperHero temp1 = first, temp2 = second, winner;
        int finRound = 0;
        
        for (int i = 0; i < max_rounds && (temp1.isAlive() && temp2.isAlive()); i++) {
            temp1 -= (temp2.attackStrength() - temp1.defend());
            temp2 -= (temp1.attackStrength() - temp2.defend());
            finRound = i;
        }
        ++finRound;
        
        if (!temp1.isAlive() && !temp2.isAlive()) {
            winner = temp1;
            std::cout
            << "Super Fight! " << first.getName() << " vs " << second.getName()
            << " : Winner is " << winner.getName() << " in " << finRound << " rounds."
            << std::endl;
            return first;
        }
        else if (!temp1.isAlive()) {
            winner = temp2;
            std::cout
            << "Super Fight! " << first.getName() << " vs " << second.getName()
            << " : Winner is " << winner.getName() << " in " << finRound << " rounds."
            << std::endl;
            return second;
        }
        else if (!temp2.isAlive()) {
            winner = temp1;
            std::cout
            << "Super Fight! " << first.getName() << " vs " << second.getName()
            << " : Winner is " << winner.getName() << " in " << finRound << " rounds."
            << std::endl;
            return first;
        }
        else {
            return first;
        }
    }
}
