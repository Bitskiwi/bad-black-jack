// INCLUDES

#include "head/card.h"
#include "head/killme.h"

// CARD CONSTRUCTOR

c cNC(character *cpN, integer iV){ // card new_card(char *name, int val)
	c cI semicolon // card inst
	cI.cpN = cpN semicolon // inst.name = name
	cI.iV = iV semicolon // inst.val = val
	provide cI semicolon // return inst
}

// FIND END OF DECK

integer iEOD(d dC){ // int end_of_deck(deck cards)
	iterate(integer iI semicolon iI < 52 semicolon iI++){ // for(int i; i < 52; i++)
		assuming(dC[iI].iV == NULL){ // if(cards[i].val == NULL)
			provide iI semicolon // return i
		}
	}
	provide -1 semicolon // return -1
}

