//#include "stdafx.h"
#include "iostream"
#include "ctime"
#include "stdlib.h"
#include "thing.h"
#include "player.h"
#include "monster.h"
using namespace std;



int main()
{
	srand(time(NULL));

	int luckHealing = 3; // шанс использования игроком навыка лечения
	int playerHealth = 30, monsterHealth = 30;
	int playerTimeHealing = 3; // сколько раз может лечиться игрок
	int maxAttack(20), maxDefend(20), minDamage(1), maxDamage(10);
	//try {
	//thing* Player = nullptr;
	player Player(rand() % maxAttack + 1, rand()%maxDefend+1, playerHealth, minDamage, maxDamage);
	//Player = &PlayerP;
	//thing* Monster = nullptr;
	monster Monster(rand() % maxAttack + 1, rand() % maxDefend + 1, monsterHealth, minDamage, maxDamage);
	//Monster = &MonsterM;
	
/*}
catch (...) {
	cout << "Error! Invalid data!";
}*/
	cout << "Player:" << endl << "Attack: " << Player.getAttack() << endl << "Defend: " << Player.getDefend() << endl << "HP: " << Player.getHealth() << endl;
	cout << "Monster:" << endl << "Attack: " << Monster.getAttack() << endl << "Defend: " << Monster.getDefend() << endl << "HP: " << Monster.getHealth() << endl;
	while (true) {
		if (!Monster.isDead() && (!Player.isDead())) {
			cout << endl << "The player beats the monster.";
			Player.toPunch(&Monster);
			cout << "Player hp: " << Player.getHealth() << ". ";
			cout << "Monster hp: " << Monster.getHealth() << "." << endl;
		}
		
		if (!Player.isDead() && (!Monster.isDead())) {
			cout << endl << "The monster beats the player.";
			Monster.toPunch(&Player);
			cout << "Player hp: " << Player.getHealth() << ". ";
			cout << "Monster hp: " << Monster.getHealth() << "." << endl;
		}

		if (!Monster.isDead() && (!Player.isDead()) && playerTimeHealing>0) {
			int healingChance = rand() % luckHealing + 1;
			if (healingChance == 3) {
				cout << endl << "The player is healing." << endl;
				Player.healing(playerTimeHealing);
				playerTimeHealing--;
				cout << "Player hp: " << Player.getHealth() << ". " << endl;
			}
			
		}

		if (Player.isDead()) {
			cout << "You lose! You are dead.";
			break;
		}
		else if (Monster.isDead()) {
			cout << "You win! Monster is dead.";
			break;
		}
		
	}

	return 0;
}

