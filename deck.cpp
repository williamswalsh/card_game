//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			deck.cpp
//	Author:			William Walsh
//	Date:			26-10-16
//	Elaboration:	deck class member function definitions.
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "deck.h"
using namespace std;
//fx defn/////////////////////////////////////////////////////////////////////////////////

/*
 Generates a Standard Deck of playing cards - 52 Cards in total
 4 suits each suit has 13 ranks.
*/
void deck::generate(){
	myDeck.reserve(deckSize);
	for(int i=2;i<15;i++){
		for(int j=1;j<5;j++){
			myDeck.push_back(card(i,j));
		}
	}
}

/*
 Shuffle function seeds rand function with time as the seed.
 rand function is used to select two numbers from 0-51.
 These numbers are then used to select the cards to swap values in the deck.
 So instead of removing one card and replacing another card in its place,
 the function swaps the member variable values.
 This process of seeding, selecting and swapping is repeated in a for loop an arbitrary number(10000) of times.
*/
void deck::shuffle(){
	
	int randomInstA,randomInstB,rounds;
	card tempA,tempB;

	// randomizer rounds
	for(rounds = 0; rounds <=10000;rounds++){
		srand((unsigned int)time(NULL));		// Seed rand each round with time
		// current round rand values
		randomInstA = (rand()%52);	// A selector 0-51 >> vector has zero based index
		randomInstB = (rand()%52);	// B selector
		// capture Cards
		tempA = myDeck[randomInstA];	
		tempB = myDeck[randomInstB];	
		// swap values
		myDeck[randomInstA] = tempB;
		myDeck[randomInstB] = tempA;
	}	
}