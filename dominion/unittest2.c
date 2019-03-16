#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

//testing the gainCard function
//int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state)

int main()
{
	struct gameState testGame;

	printf("Testing initializeGame():\n");

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int thisPlayer = 0;
	int seed = 42;

	initializeGame(numPlayers, k, seed, &testGame);

	printf("Testing number of players: ");
	
	if(testGame.numPlayers == numPlayers)
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("Testing starting hand: ");

	if(testGame.deck[0][0] == adventurer && testGame.deck[0][4] == mine)
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("%i", testGame.hand[0][0]);
}
