/*
 * Notes: the adveture card should cause the player to draw until they have draw to treasure cards which are added to there hand. All other should be discarded.
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
	int tresurerProb = 30; //prbabilaty or a card being 3 in this int

	//set up varible to be used
	int i, j;
	int tresurerCountStart;
	int tresurerCountEnd;
	int discardedCopper, discardedSilver, discardedGold;
	int passFail;
	int passed = 0;
	int tooMany = 0;
	int tooFew = 0;
	int copperFail = 0;
	int silverFail = 0;
	int goldFail = 0;

	struct gameState G;

	//set random varibles, randomize inside loop
	int deckcount;
	int randCard;

	srand(time(NULL));

	for(i=0; i<numIter; i++)
	{
		//setup

		initializeGame(numPlayers, k, seed, &G);

		deckcount = rand() % MAX_DECK;

		G.handCount[curPlayer] = rand() % (deckcount+1);
		G.deckCount[curPlayer] = deckcount - G.handCount[curPlayer];

		//I could set for all players, buyt since there turns never come up and this card should not efect them, also I am not testing
		//there deck anyway this seems a bit pointless, It my be worth considering doing if that needs to be tested, just nest a for loop.
		for(j=0; j<G.deckCount[curPlayer]; j++)
		{
			randCard = rand() % tresurerProb;

			if(randCard == 0)
			{
				G.deck[curPlayer][j] = copper;
			}
			else if(randCard == 1)
			{
				G.deck[curPlayer][j] = silver;
			}
			else if(randCard == 2)
			{
				G.deck[curPlayer][j] = gold;
			}		
			else
			{
				G.deck[curPlayer][j] = k[rand() % 10];
			}
		}

		//count treasure in hand at start.
		for(j=0; j<G.handCount[curPlayer]; j++)
		{
			if(G.hand[curPlayer][j] == copper || G.hand[curPlayer][j] == silver || G.hand[curPlayer][j] == gold)
			{
				tresurerCountStart++;
			}
		}

		//play card
		ref_adventurer(&G, 0, 0, 0);

		//count treasures after
		for(j=0; j<G.handCount[curPlayer]; j++)
		{
			if(G.hand[curPlayer][j] == copper || G.hand[curPlayer][j] == silver || G.hand[curPlayer][j] == gold)
			{
				tresurerCountEnd++;
			}
		}

		//count discarded coins
		discardedCopper = 0;
		discardedSilver = 0;
		discardedGold = 0;

		for(j=0; j<G.discardCount[curPlayer]; j++)
		{
			if(G.discard[curPlayer][j] == copper)
			{
				discardedCopper++;
			}
			else if(G.discard[curPlayer][j] == silver)
			{
				discardedSilver++;
			}
			else if(G.discard[curPlayer][j] == gold)
			{
				discardedGold++;
			}
		}

		//check pass conditions
		passFail = 1;

		if(tresurerCountEnd > (tresurerCountStart + 2))
		{
			//printf("Test Failled: Too many tresures where added.\n\n");
			tooMany++;
			passFail = 0;
		}

		if(tresurerCountEnd < (tresurerCountStart + 2))
		{
			//printf("Test Failled: Too few tresures where added.\n\n");
			tooFew++;
			passFail = 0;
		}

		if(discardedCopper != 0)
		{
			//printf("Test Failled: Copper was discarded.\n\n");
			copperFail++;
			passFail = 0;
		}

		if(discardedSilver != 0)
		{
			//printf("Test Failled: Silver was discarded.\n\n");
			silverFail++;
			passFail = 0;
		}

		if(discardedGold != 0)
		{
			//printf("Test Failled: Gold was discarded.\n\n");
			goldFail++;
			passFail = 0;
		}

		if(passFail != 0)
		{
			//printf("All Tests Passed.\n\n");
			passed++;
		}

	}

	printf("%d of %d Tests Passed.\n", passed, numIter);
	printf("%d of %d Added too many tresures.\n", tooMany, numIter);
	printf("%d of %d Added too few tresures.\n", tooFew, numIter);
	printf("%d of %d Copper was discarded.\n", copperFail, numIter);
	printf("%d of %d Silver was discarded.\n", silverFail, numIter);
	printf("%d of %d Gold was discarded.\n", goldFail, numIter);

	return 0;
}
