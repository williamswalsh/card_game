//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			Card class definition
//	Author:		William Walsh
//	Date:			26-10-16
//	Time:			02:51
//	Book:			
//	Listing:
//	Elaboration:	card class definition with forward declarations for functions.
//					corresponding fxs are listed in card.cpp
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#ifndef DECK_H
#define DECK_H
#include "card.h"		//card not declared in scope otherwise
#include <vector>
using namespace std;	//Required for vector
//class definition////////////////////////////////////////////////////////////////////////
class deck{
public:
	int deckSize;	
	vector<card> myDeck;
	deck(){}
	deck(int noOfCards):deckSize(noOfCards){}
	void generate();
	void shuffle();
	void deal();
};	//End of deck class
#endif



