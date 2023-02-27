#include "player.h"
//#include "stdafx.h"

player::player(int at, int df, int hl, int dm1, int dm2) :thing(at, df, hl, dm1, dm2) { setMaxHealth(hl); }

void player::setMaxHealth(int maxhl)
{
	maxHealth = maxhl;
}

int player::getMaxHealth() {
	return maxHealth;
}

void player::healing(int count_a) {
	if (count_a > 0) {
		if (getHealth() <= getMaxHealth() - getMaxHealth() / 2) {
			setHealth(getHealth() + getMaxHealth() / 2);
		}
		else {
			setHealth(getMaxHealth());
		}
	}
}

