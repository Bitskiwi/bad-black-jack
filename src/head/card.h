// HEADER GUARD

#ifndef CARD_H
#define CARD_H

// INCLUDES

#include "killme.h"

// CARD STRUCT

define_type structure {
	character cN; // char name
	integer iV; // int val
} c; // card

// CARD CONSTRUCTOR

c cNC(character cN, integer iV); // card new_card(char name, int val)

// DECK TYPE

define_type structure { // typedef struct { card cards[52]; } deck;
	c cC[52];
} d;

// FIND END OF DECK

integer iEOD(d dC); // int end_of_deck(deck cards)

// APPEND TO DECK

d dATD(d dC, c cX); // deck append_to_deck(deck cards, card x)

// HAND TYPE

define_type structure {
	c cC[20]; // hand.cards
} h;

// FIND END OF HAND

integer iEOH(h hC); // int end_of_hand(hand cards)

// APPEND TO HAND

h hATH(h hC, c cX); // deck append_to_hand(hand cards, card x)

// DRAW CARD

h hDC(d dC, h hC); // hand draw_card(deck cards, hand cards2)

// COUNT TOTAL HAND

integer iCTH(h hC); // int count_total_hand(hand cards)

// GENERATE DEFAULT DECK 

d dGDD(); // deck gen_default_deck()

#endif
