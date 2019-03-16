/*
 * Notes: the treasure sould trash all maps in the players hand and if 2 or more were removed add 4 gold to the players deck.
 */

#include "dominion.h"
#include "dominion_helpers.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
	//set numbers to be used
	int numIter = 10000; //number of iterations to be used
	int curPlayer = 0; //this should not matter... need more thought on that.
	int numPlayers = 2; //original random, removed do to not interacting with other players.
	int seed = 117;
	int k[10] = {adventurer, smithy, steward, cutpurse, ambassador, embargo, outpost, treasure_map, sea_hag, council_room}; //should not matter what these are

	//set varibles to use
	struct gameState G;
	int i, j;
	int deckcount;
	int mapsStart;
	int mapsEnd;
	int handPos;
	int goldCount;
	int goldAdd;
	int tooFewMaps = 0;
	int noGoldGain = 0;
	int mapsRemain = 0;
	int passFail;
	int passed = 0;

	//set random
	srand(time(NULL));

	for(i=0; i<numIter; i++)
	{
		//setup
		initializeGame(numPlayers, k, seed, &G);

		deckcount = rand() % MAX_DECK;

		G.handCount[curPlayer] = rand() % (deckcount+1) + 1;
		G.deckCount[curPlayer] = deckcount - G.handCount[curPlayer];

		for(j=0; j<G.handCount[curPlayer]; j++)
		{
			G.hand[curPlayer][j] = k[rand() % 10];
			if(G.hand[curPlayer][j] == treasure_map)
			{
				mapsStart++;
			}
		}

		handPos = rand() % G.handCount[curPlayer];

		G.hand[curPlayer][handPos] = treasure_map; //it would be a bit pointless if there was no map to play.

		for(j=0; j<G.deckCount[curPlayer]; j++)
		{
			G.deck[curPlayer][j] == smithy;
		}

		for(j=0; j<G.handCount[curPlayer]; j++)
		{
			if(G.hand[curPlayer][j] == treasure_map)
			{
				mapsStart++;
			}
		}

		treasureMapFun(curPlayer, &G, handPos);

		for(j=0; j<G.handCount[curPlayer]; j++)
		{
			if(G.hand[curPlayer][j] == treasure_map)
			{
				mapsEnd++;
			}
		}

		goldCount = 0;
		for(j=G.deckCount[curPlayer]-1; j>G.deckCount[curPlayer]-5; j--)
		{
			if(G.deck[curPlayer][j] == gold)
			{
				goldCount++;
			}
		}

		if(goldCount == 4)
		{
			goldAdd = 1;
		}
		else
		{
			goldAdd = 0;
		}

		passFail = 1;

		if(mapsStart < 2 && goldAdd == 1)
		{
			tooFewMaps++;
			passFail = 0;
		}

		if(mapsStart > 1 && goldAdd == 0)
		{
			noGoldGain++;
			passFail = 0;
		}

		if(mapsEnd > 0)
		{
			mapsRemain++;
			passFail = 0;
		}

		if(passFail != 0)
		{
			passed++;
		}
	}

	printf("%d of %d tests added gold with two few maps.\n", tooFewMaps, numIter);
	printf("%d of %d tests did not add gold.\n", noGoldGain, numIter);
	printf("%d of %d tests did not remove all of the maps.\n", mapsRemain, numIter);
	printf("%d of %d tests passed all the tests.\n", passed, numIter);

	return 0;
}
