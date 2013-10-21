// Create A Battleship Game
// Lab_8 Project #1 
// CS13001
// Zachary Jindra	
// 10/19/2013

#include "functions.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	ship ships[FLEET_SIZE];
	initialize(ships);
	deploy(ships);

	char answer;
	bool shipsUp = true;

	while(shipsUp)
	{
		shipsUp = false;
		cout << "would you like to know the ship locations? Answer y or n" << endl;
		cin >> answer;

		if (answer == 'y')
			printFleet(ships);

		fire(ships);

		for(int i = 0; i < FLEET_SIZE; ++i)
		{
			if (ships[i].sunk == false)
			{
				shipsUp = true;
			}
		}
	}

	cout << "Congratlations! YOU ARE THE WINNER!" << endl;

	return 0;
}
