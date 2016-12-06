//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			deck class definition
//	Author:			William Walsh
//	Date:			26-10-16
//	Elaboration:	deck class definition with forward declarations for functions.
//					corresponding functions are listed in deck.cpp
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#ifndef DECK_H
#define DECK_H
#include "card.h"		//card not declared in scope otherwise
#include <vector>
using namespace std;
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
};	
#endif



