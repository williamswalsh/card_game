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
#ifndef CARD_H
#define CARD_H
//#include <string> // string required??
//class definition////////////////////////////////////////////////////////////////////////
class card{
private:
	// Var
	int rank,suit;
public:	
	// shows
	std::string showRank();
	std::string showSuit();
	std::string show();
	
	// gets
	int getRank();
	int getSuit();

	// Sets
	void setRank(int rankIn);
	void setSuit(int SuitIn);
	void set(int rankIn, int suitIn);

	// Constructors
	card(){}
	card(int rankIn,int suitIn):rank(rankIn),suit(suitIn){}
};	//End of card class
#endif



