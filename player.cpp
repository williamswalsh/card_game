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
// string not required as no strings present types in file
#include "player.h"
using namespace std;
//fx defn/////////////////////////////////////////////////////////////////////////////////
void player::showHand(){
	int size = hand.size();
	if(size == 0){
		cout << "player>>showHand>>hand.size()==0" << endl;
	}
	for(int i=0;i<size;i++){	// 5 cards >> 0-4
		cout << hand[i].show();
	}
}
void player::showCard(int sel){
	 hand[sel].show();
}
int player::getNumCards(){
	return hand.size();
}
void player::showNumCards(){
	cout << hand.size();
}
card player::getCard(int sel){
	return hand[sel-1];
}

