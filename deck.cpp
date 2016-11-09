//////////////////////////////////////////////////////////////////////////////////////////
//	Title:
//	Author:			William Walsh
//	Date:
//	Time:
//	Book:			C++ for Dummies - Book4 - Advanced Programming
//	Listing:
//	Elaboration:
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "deck.h"
using namespace std;
//fx defn/////////////////////////////////////////////////////////////////////////////////
void deck::generate(){
	myDeck.reserve(deckSize);
	//card &dPtr = myDeck.back();		// Returns a reference to the last object in the vector
	for(int i=2;i<15;i++){
		for(int j=1;j<5;j++){
			myDeck.push_back(card(i,j));
		}
	}
}
void deck::shuffle(){
	srand((unsigned int)time(NULL));		// Seed rand 
	int randomInstA,randomInstB,rounds;
	card tempA,tempB;

	// randomizer rounds
	for(rounds = 0; rounds <=10000;rounds++){
		// current round rand values
		randomInstA = (rand()%52);	// A selector 0-51 array indexing 0
		randomInstB = (rand()%52);	// B selector 0-51 vect zero based index
		// capture Cards
		tempA = myDeck[randomInstA];	
		tempB = myDeck[randomInstB];	
		// swap values
		myDeck[randomInstA] = tempB;
		myDeck[randomInstB] = tempA;
	}	
}
void deck::deal(){

}



