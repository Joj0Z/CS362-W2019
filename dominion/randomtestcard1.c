/*
 * Notes: the smithy should cause you to draw 3 cards.
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
	int i;
	int deckcount;	
	int handStart;
	int deckStart;
	int discardStart;
	int handEnd;
	int deckEnd;
	int discardEnd;
	int tooManyH = 0;
	int tooFewH = 0;
	int tooManyD = 0;
	int tooFewD = 0;
	int tooManyDi = 0;
	int tooFewDi = 0;
	int passFail;
	int passed = 0;

	//set random


	srand(time(NULL));

	for(i=0; i<numIter; i++)
	{
		//setup

		initializeGame(numPlayers, k, seed, &G);

		deckcount = rand() % MAX_DECK;

		G.handCount[curPlayer] = rand() % (deckcount+1);
		G.deckCount[curPlayer] = deckcount - G.handCount[curPlayer];

		handStart = G.handCount[curPlayer];
		deckStart = G.deckCount[curPlayer];
		discardStart = G.discardCount[curPlayer];

		smithyFun(curPlayer, &G, G.hand[curPlayer][G.handCount[curPlayer] - 1]);

		handEnd = G.handCount[curPlayer];
		deckEnd = G.deckCount[curPlayer];
		discardEnd = G.discardCount[curPlayer];


		passFail = 1;

		if(handStart > (handEnd + 2)) //note: you should lost one from playing the card.
		{
			tooManyH++;
			passFail = 0;
		}

		if(handStart < (handEnd + 2)) //note: you should lost one from playing the card.
		{
			tooFewH++;
			passFail = 0;
		}

		if(deckStart > (deckEnd - 3))
		{
			tooManyD++;
			passFail = 0;
		}

		if(deckStart < (deckEnd - 3))
		{
			tooFewD++;
			passFail = 0;
		}

		if(discardStart > (discardEnd + 1))
		{
			tooManyDi++;
			passFail = 0;
		}

		if(discardStart < (discardEnd + 2))
		{
			tooFewDi++;
			passFail = 0;
		}

		if(passFail != 0)
		{
			passed++;
		}
	}

	printf("%d of %d tests had too many cards in hand.\n", tooManyH, numIter);
	printf("%d of %d tests had too few cards in hand.\n", tooFewH, numIter);
	printf("%d of %d tests had too many cards in deck.\n", tooManyD, numIter);
	printf("%d of %d tests had too few cards in deck.\n", tooFewD, numIter);
	printf("%d of %d tests had too many cards in discard.\n", tooManyDi, numIter);
	printf("%d of %d tests had too few cards in discard.\n", tooFewDi, numIter);
	printf("%d of %d tests passed.\n\n", passed, numIter);

	return 0;
}
