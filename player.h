#include "thing.h"
class player :
	public thing
{
public:
	player(int, int, int, int, int);
	void healing(int);
	void setMaxHealth(int);
	int getMaxHealth();
private:
	int maxHealth;
};


