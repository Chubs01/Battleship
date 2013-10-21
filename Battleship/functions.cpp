#include "functions.h"
#include <iostream>
using namespace std;

//
// Initialization function definitions
//
void initialize(ship shiparray[])
{
	for(int i = 0; i < FLEET_SIZE; ++i)
	{
		shiparray[i].loc.x = -1;
		shiparray[i].loc.y = 'x';
	}
}

// Pick function definition
location pick(void)
{
	int valueX = rand()%5;
	int valueY = rand()%5;
	location tempLocation;
	tempLocation.x = valueX;

	switch (valueY) // switches the Y variable to a letter a-e
		{
		case 0:
			tempLocation.y = 'a';
			break;

		case 1:
			tempLocation.y = 'b';
			break;

		case 2:
			tempLocation.y = 'c';
			break;

		case 3:
			tempLocation.y = 'd';
			break;

		case 4:
			tempLocation.y = 'e';
			break;

		default:
			cout << "Invalid Y value" << endl;
		}
	return tempLocation;
}

// check function definition
bool check(ship shiparray[], location testLocation, int& shipIndex)
{
	for(int i = 0; i < FLEET_SIZE; ++i) // checks for duplicates throughout all 
	{	                                // values in the array
	
		//bool isDuplicate = true;

		int valueX = testLocation.x;
		char valueY = testLocation.y;

		bool isEqualX = false;
		bool isEqualY = false;
				
		if(shiparray[i].loc.x == valueX) 
		{
			isEqualX = true;
		}

		if(shiparray[i].loc.y == valueY)
		{
			isEqualY = true;
		}

		if(isEqualX && isEqualY)		// if the values are duplicate then
		{         
			shipIndex = i;// then they are reassigned new values
			return true;
		}
	}
	return false;
}

// function definition for the Deploy function
void deploy(ship shiparray[])
{
	for(int i = 0; i < FLEET_SIZE; ++i)
	{
		int shipIndex;
		bool match = false;
		location myLocation = pick();
		match = check(shiparray, myLocation, shipIndex);
		while(match)
		{
			myLocation = pick();
			match = check(shiparray, myLocation, shipIndex);
		}
		shiparray[i].loc.x = myLocation.x;
		shiparray[i].loc.y = myLocation.y;
		shiparray[i].sunk = false;
	}
}

//
// functions that display fleet locations
//

void printShip(ship oneShip)
{
	cout << oneShip.loc.x << oneShip.loc.y << " ";
	if (oneShip.sunk)
		cout << "sunk," << " ";
	else
		cout << "up," << " ";
}

void printFleet(ship shiparray[])
{
	for (int i = 0; i < FLEET_SIZE; ++i)
	{
		printShip(shiparray[i]);
	}
}

//
// Battle function definitions
//

// fire function definiton
bool fire(ship shiparray[])
{
	location attackLocation;
	cout << "\nWhere do you want to shoot (0-4) (ROW): " ;
	cin >> attackLocation.x;
	cout << "\nWhere do you want to shoot (a-e) (Column): ";
	cin >> attackLocation.y;

	int shipIndex = -1;
	if(check(shiparray, attackLocation, shipIndex))
	{
		shiparray[shipIndex].sunk = true; // if it is a hit, it changes the status of the ship to sunk
		cout << "IT WAS A HIT!\n";
		return true;
	}
	else // does nothing
	{
		cout << "You missed.\n";
		return false;
	}
	
}