//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			player class definition
//	Author:			William Walsh
//	Date:			26-10-16
//	Elaboration:	player class definition with forward declarations for functions.
//					Corresponding functions are listed in player.cpp.
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
	// Each player has a hand - vector of cards objects
	vector<card> hand;
	void showCard(int sel);
	card getCard(int sel);
	void showHand();
	void showNumCards();
	int  getNumCards();
	
	// Always create default constructor whenever creating custom constructor.
	// If you don't you will not be able to call the default constuctor.
	player(){}
	player(int playerNo):playerNumber(playerNo){}
};
#endif



