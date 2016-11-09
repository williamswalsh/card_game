//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			Card class definition
//	Author:			William Walsh
//	Date:			26-10-16
//	Time:			02:51
//	Book:			
//	Listing:
//	Elaboration:	card class definition with forward declarations for functions.
//					corresponding fxs are listed in card.cpp
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "card.h"
using namespace std;
//class definition////////////////////////////////////////////////////////////////////////
class player{
public:
	int playerNumber;
	vector<card> hand;
	void showCard(int sel);
	card getCard(int sel);
	void showHand();
	void showNumCards();
	int  getNumCards();
	// Always create default constructor whenever creating custom constructor
	player(){}
	player(int playerNo):playerNumber(playerNo){}
};
#endif



