#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() 
{
	int seed = 42;
	int initHandSize;
	int passed = 1;

	struct gameState G;
	int k[10] = {adventurer, smithy, steward, cutpurse, ambassador, embargo, outpost, treasure_map, sea_hag, council_room};

	//setup
	initializeGame(2, k, seed, &G);

	printf("Test Smithy:\n");

	initHandSize = G.handCount[G.whoseTurn];

	cardEffect(smithy, 0, 0, 0, &G, 0, 0);

	if((initHandSize+2) != G.handCount[G.whoseTurn])
	{
		printf("Test failed: Hand size was %d should have been %d\n", G.handCount[G.whoseTurn], (initHandSize+2));

		passed = 0;
	}

	//If nessisary other test here, though since this card just draws three is is fairly simple to see if it worked or not.

	if(passed != 0)
	{
		printf("passed\n");
	}

	printf("\n");

	return 0;
}
