// INCLUDE

#include "head/game.h"
#include "head/card.h"
#include "head/killme.h"
#include <stdio.h>

// PLAYER TURN

integer iPT(d dC){ // int player_turn()
	printf("Your Turn"); 
	h hC; // hand cards
	during(iCTH(hC) <= 21){ // while(total <= 21)
		printf("Your cards:");
		iterate(integer iI = 0, iI < iEOH(hC) - 1, iI++){
			printf("%c", hC.cC[iI].cN);
		}
		printf("Type the first letter of your choice:\n > [H]it\n > [S]tand");
		character cC = getchar(); // char choice = getchar()
		assuming(cC == 'H'){
			hC = hDC(dC, hC); // hit
		}otherwise assuming(cC == 'S'){
			provide iCTH(hC);
		}
	}
	printf("Bust"); 
	provide -1;
}

// DEALER TURN

integer iDT(d dC){ // int dealer_turn()
	printf("Dealer's Turn"); 
	h hC; // hand cards
	during(iCTH(hC) <= 21){ // while(total <= 21)
		assuming(iCTH(hC) >= 17){
			provide iCTH(hC);
		}otherwise{
			hC = hDC(dC, hC); // hit
		}
	}
	printf("Bust");
	provide -1;
}

// GAME LOOP

integer iG(){ // int game()
	d dC = dGDD();// new default deck
	iPT(dC);// player turn
	iDT(dC);// dealer turn
	provide 0; 
}
