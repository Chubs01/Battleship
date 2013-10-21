#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//
// data structures definitions
//
const int FLEET_SIZE=5;	// number of battleships
const int FIELD_SIZE=5; // the field (ocean) is FIELD_SIZExFIELD_SIZE

// coordinates (location) of the ship and shots
struct location{
	int x;  // 1 through FIELD_SIZE
	char y; // 'a' through FIELD_SIZE
};

// contains ship's coordinates (location) and whether is was sunk
struct ship{
	location loc;
	bool sunk;
};

//
// initialization functions
//

void initialize(ship shiparray[]); // places all ships in -1 X location to signify
								   // that the ship is not deployed

location pick(void); // generates a random location


bool check( ship shiparray[], location , int& shipIndex); // returns true if location matches
														  // the location of one of the ships
														  // in the array
														  // uses match()

void deploy(ship shiparray[]); // places an array of battleships in
							   // random locations in the ocean

//
// display functions
//

void printShip(ship oneShip); // prints the location and status (sunk or not) 
							  // of a single ship

void printFleet(ship shiparray[]); // prints the locations of all the ships and 
								   // whether they are sunk

//
// battle functions
//

bool fire(ship shiparray[]);	// asks the user to input the coordinates of the next
								// shot
								// note that check() is also used in the battle

#endif functions_h

