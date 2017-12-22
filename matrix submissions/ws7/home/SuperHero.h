//
//  SuperHero.h
//  ws7_home-macOS
//
//  Created by Damian Murawiecki on 2017-12-09.
//  Copyright © 2017 Damian Murawiecki. All rights reserved.
//

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
    class SuperHero : public Hero {
        int bonus;
        int protection;
    public:
        SuperHero();
        SuperHero(const char* n, int h, int s, int b, int d);
        int attackStrength() const;
        int defend() const;
    };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif /* SICT_SUPERHERO_H */
