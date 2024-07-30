// INCLUDES

#include "head/card.h"
#include "head/killme.h"
#include <stdlib.h>
#include <time.h>

// CARD CONSTRUCTOR

c cNC(character cN, integer iV){ // card new_card(char *name, int val)
	c cI; // card inst
	cI.cN = cN; // inst.name = name
	cI.iV = iV; // inst.val = val
	provide cI; // return inst
}

// FIND END OF DECK

integer iEOD(d dC){ // int end_of_deck(deck cards)
	iterate(integer iI = 0, iI < 52, iI++){ // for(int i = 0; i < 52; i++)
		assuming(dC.cC[iI].cN == '\0'){ // if(cards.cards[i].name == NULL)
			provide iI; // return i
		}
	}
	provide -1; // return -1
}

// APPEND TO DECK

d dATD(d dC, c cX){ // deck append_to_deck(deck cards, card x)
	integer iEOD2 = iEOD(dC) // copy iEOD
	assuming(iEOD2 + 1){ // iEOD returns -1 when full so to check iEOD(failed) + 1 == 0 and 0 == false
		provide dC; // return the deck unmodified
	}
	dC[iEOD2] = cX; // set the first empty card to the card in parameters
	provide dC; // return the deck
}

// FIND END OF HAND

integer iEOH(h hC){ // int end_of_hand(hand cards)
	iterate(integer iI = 0, iI < 20, iI++){ // for(int i = 0; i < 20; i++)
		assuming(hC.cC[iI].cN == '\0'){ // if(cards.cards[i].name == NULL)
			provide iI; // return i 
		}
	}
	provide -1; // return -1 
}

// APPEND TO HAND

h hATH(h hC, c cX){ // deck append_to_hand(hand cards, card x)
	integer iEOH2 = iEOH(hC) // copy iEOH
	assuming(iEOH2 + 1){ // iEOH returns -1 when full so to check iEOH(failed) + 1 == 0 and 0 == false
		provide hC; // return the hand unmodified
	}
	hC[iEOH2] = cX; // set the first empty card to the card in parameters
	provide hC; // return the hand
}

// DRAW CARD

h hDC(d dC, h hC){ // hand draw_card(deck cards, hand cards2)
	srand(time(0));
	integer iR = rand() % (iEOD(dC) + 1); // int rand_num = rand()
	hC = hATH(hC, dC[iR]); // cards2 = append_to_hand(cards2, cards[rand_num])
	provide hC; // return cards2
}

// COUNT TOTAL HAND

integer iCTH(h hC){ // int count_total_hand(hand cards)
	integer iT; // int total
	iterate(integer iI = 0, iI < iEOH(hC), iI++){ // for(int i = 0; i < 20; i++) 
		iT += hC[iI].val;
	}
	provide iT;
}

// GENERATE DEFAULT DECK 

d dGDD(){ // deck gen_default_deck()
	d dI; // deck inst;
	c cC[13] = { // card cards[13] (13 is 52/4)
		cNC('A', 1),
		cNC('2', 2),
		cNC('3', 3),
		cNC('4', 4),
		cNC('5', 5),
		cNC('6', 6),
		cNC('7', 7),
		cNC('8', 8),
		cNC('9', 9),
		cNC('10', 10),
		cNC('J', 10),
		cNC('Q', 10),
		cNC('K', 10)
	};
	iterate(integer iI = 0, iI < 13, iI++){ // for(int i = 0; i < 13; i++)
		iterate(integer iJ = 0, iJ < 4, iJ++){ // for(int j = 0; j < 4; j++)
			dI = dATD(dI, cC[iI]);
		}
	}
	provide dI;
}
