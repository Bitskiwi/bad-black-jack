// HEADER GUARD

#ifndef CARD_H
#define CARD_H

// INCLUDES

#include "killme.h"

// CARD STRUCT

define_type structure {
	character *cpN semicolon // char *name
	integer iV semicolon // int val
} c semicolon // card

// CARD CONSTRUCTOR

c cNC(character *cpN, integer iV); // card new_card(char *name, int val)

// DECK TYPE

define_type c d[52] semicolon // typedef card deck[52]

// FIND END OF DECK

integer iEOD(d dC); // int end_of_deck(deck cards)

#endif
