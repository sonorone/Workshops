//
//  Hero.h
//  ws7_lab
//
//  Created by Damian Murawiecki on 2017-12-06.
//  Copyright © 2017 Damian Murawiecki. All rights reserved.
//

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>
using namespace std;

namespace sict{
	const int size = 41;
	const int max_rounds = 100;
    
    class Hero{
        char name[size];
        int health;
        int strength;
    public:
        Hero();
        Hero(const char* n,int h, int s);
        void operator-=(int attack);
        bool isAlive() const;
        int attackStrength() const;
        friend std::ostream& operator<<(ostream& os, const Hero& hero);
	const char* getName() const;
	int getHealth() const;
    };
    const Hero& operator*(const Hero& first, const Hero& second);
}
#endif /* SICT_HERO_H */
