#include "thing.h"
//#include "stdafx.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
using namespace std;


thing::thing(int at, int df, int hl, int dm1, int dm2)
{
	setAttack(at);
	setDefend(df);
	setHealth(hl);
	setDamage(dm1, dm2);
}

void thing::setAttack(int at)
{
	attack = at;
}

int thing::getAttack()
{
	return attack;
}


void thing::setDefend(int df)
{
	defend = df;
}

int thing::getDefend()
{
	return defend;
}


void thing::setHealth(int hl)
{
	health = hl;
}

int thing::getHealth()
{
	return health;
}


void thing::setDamage(int dm1, int dm2)
{
	damage1 = dm1;
	damage2 = dm2;
}


int thing::getDamage()
{
	//return make_pair(damage1, damage2);
	return (rand()%damage2+damage1);
}


int thing::computeAttackModificator(int at, int df) {
	int difference = at - df;
	if (difference <= 0) {
		return 1;
	}
	else {
		return (difference + 1);
	}
}

bool thing::isDead() {
	return (this->getHealth() <= 0);
	//if (hl <= 0) return true;
}

bool thing::isHitSuccess() {
	for (int i = 1; i <= computeAttackModificator(getAttack(), getDefend()); i++) {
		int rand_a = rand() % 6 +1;
		if ((rand_a == 5) || (rand_a == 6)) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
};

void thing::toPunch(thing* enemy) {
	if (this->isHitSuccess()) {
		//pair<int, int> p = getDamage();
		int dmg = getDamage();
		enemy->setHealth(enemy->getHealth() - dmg);
		if (enemy->getHealth() <= 0) {
			enemy->setHealth(0);
		}
		cout << "\nDamage: " << dmg << endl;
	}
	else {
		cout << "\nLose attack!" << endl;
	}
	
}


