//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			player.cpp
//	Author:			William Walsh
//	Date:			26-10-16
//	Elaboration:	player class member function definitions.
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "player.h"
using namespace std;
//fx defn/////////////////////////////////////////////////////////////////////////////////
void player::showHand(){
	int size = hand.size();
	if(size == 0){
		cout << "player>>showHand>>hand.size()==0" << endl;
	}
	for(int i=0;i<size;i++){	// 5 cards initially >> 0-4
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

