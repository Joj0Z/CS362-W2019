#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

//testing the updateCoins function
//int updateCoins(int player, struct gameState *state, int bonus)

int main()
{
	struct gameState testGame;
	
	int seed = 42;
	int players = 2;
	int k[10] = {smithy, smithy, smithy, smithy, smithy, smithy, smithy, smithy, smithy, smithy};

	initializeGame(players, k, seed, &testGame);

	printf("Testing updateCoins()\n");

	//no coins

	testGame.coins = -1; //setting the coin value to a number that should not be possible

	testGame.hand[0][0] = smithy;
	testGame.hand[0][1] = smithy;
	testGame.hand[0][2] = smithy;
	testGame.hand[0][3] = smithy;
	testGame.hand[0][4] = smithy;
	testGame.hand[0][5] = smithy;
	testGame.hand[0][6] = smithy;
	testGame.hand[0][7] = smithy;
	testGame.hand[0][8] = smithy;
	testGame.hand[0][9] = smithy;

	updateCoins(0, &testGame, 0);

	printf("Testing no coins: ");

	if(testGame.coins == 0)
		printf("Passed\n");
	else
		printf("Failed\n");
		printf("You should have 0 coin, but you have %d.\n", testGame.coins);

	testGame.coins = -1; //setting the coin value to a number that should not be possible

	//1 copper

	testGame.hand[0][0] = copper;
	testGame.hand[0][1] = smithy;
	testGame.hand[0][2] = smithy;
	testGame.hand[0][3] = smithy;
	testGame.hand[0][4] = smithy;
	testGame.hand[0][5] = smithy;
	testGame.hand[0][6] = smithy;
	testGame.hand[0][7] = smithy;
	testGame.hand[0][8] = smithy;
	testGame.hand[0][9] = smithy;

	updateCoins(0, &testGame, 0);

	printf("Testing 1 Copper: ");

	if(testGame.coins == 1)
		printf("Passed\n");
	else
		printf("Failed\n");
		printf("You should have 1 coin, but you have %d.\n", testGame.coins);

	testGame.coins = -1; //setting the coin value to a number that should not be possible

	//1 silver

	testGame.hand[0][0] = silver;
	testGame.hand[0][1] = smithy;
	testGame.hand[0][2] = smithy;
	testGame.hand[0][3] = smithy;
	testGame.hand[0][4] = smithy;
	testGame.hand[0][5] = smithy;
	testGame.hand[0][6] = smithy;
	testGame.hand[0][7] = smithy;
	testGame.hand[0][8] = smithy;
	testGame.hand[0][9] = smithy;

	updateCoins(0, &testGame, 0);

	printf("Testing 1 Silver: ");

	if(testGame.coins == 2)
		printf("Passed\n");
	else
		printf("Failed\n");
		printf("You should have 2 coin, but you have %d.\n", testGame.coins);


	testGame.coins = -1; //setting the coin value to a number that should not be possible

	//1 gold

	testGame.hand[0][0] = gold;
	testGame.hand[0][1] = smithy;
	testGame.hand[0][2] = smithy;
	testGame.hand[0][3] = smithy;
	testGame.hand[0][4] = smithy;
	testGame.hand[0][5] = smithy;
	testGame.hand[0][6] = smithy;
	testGame.hand[0][7] = smithy;
	testGame.hand[0][8] = smithy;
	testGame.hand[0][9] = smithy;

	updateCoins(0, &testGame, 0);

	printf("Testing 1 Gold: ");

	if(testGame.coins == 3)
		printf("Passed\n");
	else
		printf("Failed\n");
		printf("You should have 3 coin, but you have %d.\n", testGame.coins);


	//test 1 of each

	testGame.hand[0][0] = copper;
	testGame.hand[0][1] = silver;
	testGame.hand[0][2] = gold;
	testGame.hand[0][3] = smithy;
	testGame.hand[0][4] = smithy;
	testGame.hand[0][5] = smithy;
	testGame.hand[0][6] = smithy;
	testGame.hand[0][7] = smithy;
	testGame.hand[0][8] = smithy;
	testGame.hand[0][9] = smithy;

	updateCoins(0, &testGame, 0);

	printf("Testing 1 Gold: ");

	if(testGame.coins == 6)
		printf("Passed\n");
	else
		printf("Failed\n");
		printf("You should have 6 coin, but you have %d.\n", testGame.coins);

	//tesing hand of copper 

	testGame.hand[0][0] = copper;
	testGame.hand[0][1] = copper;
	testGame.hand[0][2] = copper;
	testGame.hand[0][3] = copper;
	testGame.hand[0][4] = copper;
	testGame.hand[0][5] = copper;
	testGame.hand[0][6] = copper;
	testGame.hand[0][7] = copper;
	testGame.hand[0][8] = copper;
	testGame.hand[0][9] = copper;

	updateCoins(0, &testGame, 0);

	printf("Testing 10 Copper: ");

	if(testGame.coins == 10)
		printf("Passed\n");
	else
		printf("Failed\n");
		printf("You should have 10 coin, but you have %d.\n", testGame.coins);

	//new line for spacing
	printf("\n");
}
