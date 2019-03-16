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
	int k[10] = {adventurer, smithy, steward, cutpurse, ambassador, embargo, outpost, treasure_map, sea_hag, council_room};

	int i;

	int tresurerCountStart = 0;
	int tresurerCountEnd = 0;
	int tresurerDiscardStart = 0;
	int tresurerDiscardEnd = 0;
	int seed = 42;
	int passed = 1;

	struct gameState G;

	initializeGame(2, k, seed, &G);

	int curPlayer = G.whoseTurn;

	printf("Test Adventurer\n");

	for(i=0; i<G.handCount[curPlayer]; i++)
	{
		if(G.hand[G.whoseTurn][i] == copper || G.hand[G.whoseTurn][i] == silver || G.hand[G.whoseTurn][i] == gold)
		{
			tresurerCountStart++;
		}
	}

	for(i=0; i<G.discardCount[curPlayer]; i++)
	{
		if(G.discard[G.whoseTurn][i] == copper || G.discard[G.whoseTurn][i] == silver || G.discard[G.whoseTurn][i] == gold)
		{
			tresurerDiscardStart++;
		}
	}

	printf("%d,", G.deckCount[curPlayer]);

	cardEffect(adventurer, 0, 0, 0, &G, 0,0);

	printf("%d", G.deckCount[curPlayer]);

	for(i=0; i<G.handCount[curPlayer]; i++)
	{
		if(G.hand[G.whoseTurn][i] == copper || G.hand[G.whoseTurn][i] == silver || G.hand[G.whoseTurn][i] == gold)
		{
			tresurerCountEnd++;
		}
	}

	for(i=0; i<G.discardCount[curPlayer]; i++)
	{
		if(G.discard[G.whoseTurn][i] == copper || G.discard[G.whoseTurn][i] == silver || G.discard[G.whoseTurn][i] == gold)
		{
			tresurerDiscardEnd++;
		}
	}

	if((tresurerCountStart+2) != tresurerCountEnd)
	{
		printf("Test Failed: Expected tresurer %d Acual %d\n", (tresurerCountStart+2), tresurerCountEnd);

		passed = 0;
	}

	if(tresurerDiscardEnd > tresurerDiscardStart)
	{
		printf("Test Failed: Expected discard %d Acual %d\n", tresurerDiscardStart, tresurerDiscardEnd);

		passed = 0;
	}

	if(passed != 0)
	{
		printf("Passed\n");
	}

	printf("\n");

	return 0;
}
