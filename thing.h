#pragma once
#include "stdlib.h"
using namespace std;

class thing
{
public:
	thing(int, int, int, int, int);
	int getAttack();
	void setAttack(int);
	int getDefend();
	void setDefend(int);
	int getHealth();
	void setHealth(int);
	int getDamage();
	void setDamage(int, int);
	bool isDead();
	bool isHitSuccess();
	void toPunch(thing*);
private:
	int attack, defend, health, damage1, damage2;
protected:
	int computeAttackModificator(int, int);
};

