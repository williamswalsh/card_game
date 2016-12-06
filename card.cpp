//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			card.cpp
//	Author:			William Walsh
//	Date:			26-10-16
//	Elaboration:	card class member function definitions.
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "card.h"
using namespace std;
//fx defn/////////////////////////////////////////////////////////////////////////////////
/*
 showRank()
 returns rank of card in string form
*/
string card::showRank(){
	string rankStr;
	switch(rank){
		case 0:		
		rankStr = "zero - error!";
		break;
		case 1:				
		rankStr = "one - error!";
		break;
		case 2:
		rankStr = "2";
		break;
		case 3:
		rankStr = "3";
		break;
		case 4:
		rankStr = "4";
		break;
		case 5:
		rankStr = "5";
		break;
		case 6:
		rankStr = "6";
		break;
		case 7:
		rankStr = "7";
		break;
		case 8:
		rankStr = "8";
		break;
		case 9:
		rankStr = "9";
		break;
		case 10:
		rankStr = "10";
		break;
		case 11:
		rankStr = "J";
		break;
		case 12:
		rankStr = "Q";
		break;
		case 13:
		rankStr = "K";
		break;
		case 14:				
		rankStr = "A";
		break;
		default:
		rankStr = "Invalid Value - Default_switch_case_show_rank";
		break;
	}	//End of switch(rank)
	return rankStr;
}
/*
 showSuit()
 returns suit of card in string form
 uses unicode to display card suit symbols.
*/
string card::showSuit(){
	string suitStr;
	switch(suit){
		case 0:
		suitStr = "zero - error!";
		break;
		case 1:
		suitStr = "\u2660";			// 1 - (Black) Spade
		break;
		case 2:
		suitStr = "\u2663";			// 2 - Club
		break;
		case 3:
		suitStr = "\u2665";			// 3 - Heart
		break;
		case 4:
		suitStr = "\u2666";			// 4 - Diamond
		break;
		default:
		suitStr = "Invalid Value - Default_switch_case_show_suit";
		break;
	}	//End of switch(suit)
	return suitStr;
}
/*
 show()
 returns concatenation of card suit and card rank in string form
*/
string card::show(){
	string a = showRank();
	string b = showSuit();
	return a+b;	//Concatenate strings
}
int card::getRank(){
	return rank;
}
int card::getSuit(){
	return suit;
}
void card::setRank(int rankIn){
	rank = rankIn;
}
void card::setSuit(int suitIn){
	suit = suitIn;
}						
void card::set(int rankIn, int suitIn){
	setRank(rankIn);
	setSuit(suitIn);
}			





