//
//  Hero.cpp
//  ws7_lab
//
//  Created by Damian Murawiecki on 2017-12-07.
//

#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict {
	Hero::Hero() {
		name[0] = '\0';
		health = -1;
		strength = -1;
	}
	Hero::Hero(const char* n, int h, int s) {
		if (n[0] != '\0' && h != -1 && s != -1) {
			std::strncpy(name, n, size);
			name[size] = '\0';
			health = h;
			strength = s;
		}
		else {
			*this = Hero();
		}
	}

	/* an overloaded operator that receives an attack strength and, if that strength is positive-valued, deducts that
	 * strength from the current object’s health. If the attack strength re-ceived is not positive-valued,
	 * this operator does nothing. If the deduction drops the current object’s health below 0, this operator re-sets its health to 0.
	 */
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
			if (health < 0)
				health = 0;
		}
	}

	/* a query that returns true if the current object is healthy and false otherwise.
	 */
	bool Hero::isAlive() const { return health > 0; }

	/* a query that returns attack strength of the current object. If the object is in a safe empty state, this function re-turns 0.
	 */
	int Hero::attackStrength() const {
		return strength != -1 ? strength : 0;
	}

	/* a friend that inserts the name of hero into stream os and returns a reference to that stream.
	 * If hero is in a safe empty state, this function displays the mes-sage:
	 */
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.name[0] != '\n' && hero.health != -1 && hero.strength != -1)
			os << hero.name;
		else
			os << "No hero";
		return os;
	}

	/* a non-friend that returns an unmodifiable reference to the winner of the battle between
	 * the Heroes after max_rounds rounds.
	 * This function displays the names of the battle
	 * participants as shown in the sample out-put below, makes local copies of the participants,
	 * determines the dam-age that each inflicts on the other in a single attack and battles until
	 * either one of the participants dies or the maximum number of rounds is reached.

	 In each round,
	 * this function deducts the damage inflicted on a Hero by the other Hero. Finally, this function
	 * displays the name of the winner. In the case of a draw, this function assumes arbitrarily that the
	 * left operand (first) has won. This function returns a reference to the winner object.
	 */
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero temp1 = first, temp2 = second, winner;
		int finRound = 0;

		for (int i = 0; i < max_rounds && (temp1.isAlive() && temp2.isAlive()); i++) {
			temp1 -= temp2.attackStrength();
			temp2 -= temp1.attackStrength();
			finRound = i;
		}
		++finRound;

		if (!temp1.isAlive() && !temp2.isAlive()) {
			winner = temp1;
			std::cout
				<< "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << first.getName() << " in " << finRound << " rounds."
				<< std::endl;
			return first;
		}
		else if (!temp1.isAlive()) {
			winner = temp2;
			std::cout
				<< "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << finRound << " rounds."
				<< std::endl;
			return second;
		}
		else if (!temp2.isAlive()) {
			winner = temp1;
			std::cout
				<< "Ancient Battle! " << first.getName() << " vs " << second.getName()
				<< " : Winner is " << winner.getName() << " in " << finRound << " rounds."
				<< std::endl;
			return first;
		}
		else {
			return first;
		}
	}

	const char* Hero::getName() const { return name; }
	int Hero::getHealth() const { return health; }
}








