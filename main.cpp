//////////////////////////////////////////////////////////////////////////////////////////
//	Title:			main.cpp 
//	Author:			William Walsh
//	Date:			7-Nov-2016
//	Elaboration:	main file for a card game called "Palace".
//					Each class has its own header file and cpp file.
//					Header file contains member variables, function declarations and constructors.
//					Associated cpp file contains function definitions.
//////////////////////////////////////////////////////////////////////////////////////////
//pre-processor///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>	// setw() function
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;
//fx defn/////////////////////////////////////////////////////////////////////////////////

/*
 Initial deal of cards at beginning of a game
 Parameters	pointers to player 1 object and player 2 object and pointer to a full deck of cards
 Return		void
*/
void initialDeal(player *p1,player *p2,deck *deck){
	card tmp;
	while(p1->hand.size() <5 || p2->hand.size() <5){	// Only exits while loop once both 
														// players have 5 cards.
		tmp = deck->myDeck.back();						
		deck->myDeck.pop_back();
		p1->hand.push_back(tmp);
		
		tmp = deck->myDeck.back();
		deck->myDeck.pop_back();
		p2->hand.push_back(tmp);
	}
}
int findCardSameRank(player *currPlayer,int cardSelect){
	int save = -1;
	int rank = currPlayer->hand[cardSelect].getRank();

	int i;		// ERROR: if define int i within for loop >> name lookup of ‘i’ changed for ISO ‘for’ scoping [-fpermissive]
	for( i=0; i<currPlayer->hand.size(); i++ ){
		if(rank == currPlayer->hand[i].getRank()){
			save = i;
		}
	}
	return i;
}
/* selectCard prompts player to select a card to play from hand
 Parameter - pointer to player
 return - int - 0-4 card selected
*/
int selectCard(player *currPlayer){
	int cardSelect = 52; // 0-51 - (52 >> Invalid selection)
	cout << endl;
	cout << "Player " << currPlayer->playerNumber << " Which card would you like to play? ";
	cin >> cardSelect;	// 1 = 1st card		

	// while player selects a cards position larger than hand size.
	// or player selects a card position that is less than 1.
	while(cardSelect > currPlayer->getNumCards() || cardSelect < 1){	
		cout << "Player " << currPlayer->playerNumber << " Invalid Selection. Choose a number from 1 to " << currPlayer->hand.size() << endl;
		cin >> cardSelect;		// if invalid selection >> reject & re-ask
	}
	return cardSelect;
}


void playCard(player *currPlayer,deck *faceUp, int cardSelect){
	card tmp;
	tmp = currPlayer->getCard(cardSelect);		// Tmp card obj to store card instance
	faceUp->myDeck.push_back(tmp); 				// Place into faceUp deck	
	currPlayer->hand.erase(currPlayer->hand.begin()+cardSelect-1);	// Remove card from hand
}

// draw a card from the faceDown deck
void draw(player *currPlayer,deck *aDeck){
	card tmp = aDeck->myDeck.back();
	aDeck->myDeck.pop_back();
	currPlayer->hand.push_back(tmp);
}

void collectPile(player *currPlayer,deck *aDeck){
	// .size()=10 i=0-9 ~ 10 loops
	int cardsToDraw = aDeck->myDeck.size();	// Capture size initially once as draw updates myDeck.size() with each call to draw()
	for(int i = 0;i<cardsToDraw;i++){		// Draw each card in deck
		draw(currPlayer,aDeck);
	}
}
void displayFaceUp(deck *faceUp){
	if(!faceUp->myDeck.empty()){
		cout << "FaceUpDeck: " << faceUp->myDeck.back().show() << endl;
	}else{
		cout << "FaceUpDeck: " << endl;
	}
}
// Sorts cards in players hand in ascending order based on rank
void sortHand(player *player){
	int tmp;
	int sortCount = player->hand.size();

	for(int j=0;j<=sortCount;j++){					// Number of sortLoops
		for(int i=0;i<(player->hand.size()-1);i++){
			if(player->hand[i].getRank() > player->hand[i+1].getRank()){	// swap if a > b
				tmp = player->hand[i].getRank();							// tmp = a;
				player->hand[i].setRank(player->hand[i+1].getRank());		// a = b;
				player->hand[i+1].setRank(tmp);								// b = tmp;
			}
		}
	}
}
void displayHand(player *player){
	int cardWidth = 7;	
	
	cout << left;
	cout << setw(10) << "Card" << "	";
	for(int i=1;i<=player->hand.size();i++){
		cout << setw(5) << i;
	}cout << endl;

	cout << setw(10) << "Player: " << setw(5) << player->playerNumber << setw(cardWidth);
	for(int i=1;i<=player->hand.size();i++){
		if(player->hand[i-1].getRank() != player->hand[i].getRank()){	// If cards are not of same rank print large space
			cout << setw(cardWidth);
		}else{
			cout << setw(6);												// If cards are same rank print small space
		}
		cout << player->hand[i-1].show();
	}cout << endl;
}
void displayAllHands(vector<player> *playerSet){
	//get max size
	int max = 0;

	for(int j=0;j<playerSet->size();j++){
		if( (*playerSet)[j].hand.size() > max ){
			max = ((*playerSet)[j].hand.size());
		}
	}
	cout << left;
	cout << setw(10) << "Card" << "	";
	for(int i=1;i<=max;i++){
		cout << setw(5) << i;
	}cout << endl;
	
	for(int i=0;i<playerSet->size();i++){
		displayHand(&(*playerSet)[i]);		// Note syntax - (&(*myVect)[index])
	}
}

bool validCard(player* currPlayer,deck *faceUp,int cardSelect, bool* burnFlag){
	/* Rules
	 NB: Return False if no corresponding rule to make card valid - Failsafe **
	
	 If no cards in faceUp deck >> you can pay any card >> any card valid
	 If selected card 2 >> You can play it on anything >> Next card is >2
	 If selected card 3 >> Card Valid >> Next card >> previous card effect
	 selected 7 >> play on <7 >> next card <7 
	 selected 8 >> skip next player move
	 10 >> play on anything >> empty faceUp >> same player move ** 

	 Must test what was last card played before checking what player cards are higher priority
	 EG faceUp 8 must be tested first before any possible plays of card *********** NB
	*/
		
	// Rule # - 10 can be played on all cards except 8 which cannot be played on
	if(currPlayer->getCard(cardSelect).getRank() == 10){
		// empty faceUpdeck - completed in while loop
		//faceUp->myDeck.
		// Allow player to play another card - flag
		*burnFlag = true;
		return true;
	}

	// Rule #1 - If no faceUp deck(No previous cards to check) any card can be played
	if(faceUp->myDeck.empty()){			
		return true;
	}

	// Rule #2 - 2 can be played on anything
	if(currPlayer->getCard(cardSelect).getRank() == 2){
		return true;
	}
	// Rule #3 - 3 can be played on anything >> mirrors lower card
	if(currPlayer->getCard(cardSelect).getRank() == 3){
		return true;
	}
	
	// Rule #3b - if 3 is top of faceUp deck
	if(!faceUp->myDeck.empty()){						// Must test if deck has cards otherwise .back() leads to seg fault
		if(faceUp->myDeck.back().getRank() == 3 && faceUp->myDeck.size()>=2){
			if(currPlayer->getCard(cardSelect).getRank() >= faceUp->myDeck[faceUp->myDeck.size()-2].getRank() ){	// 2nd last card
				return true;
			}else{
				return false;
			}
		}
	}
	
	// Rule #4 - if top of deck is 7 >> flip priority order 
	// >> cards must be of lower value for the time when 7 is the top of the deck
	if(!faceUp->myDeck.empty()){						// If deck is not empty
		if(faceUp->myDeck.back().getRank() == 7 ){
			if(currPlayer->getCard(cardSelect).getRank() <= 7){
				return true;
			}else{
				return false;	// If this is not present next rule will deal with this case incorrectly
			}
		}
	}

	// Rule #6 - 
	// in general larger priority is valid once all special cases are tested first 2,3,7,8,10
	// 7 can be played on < 7 therfore >> no rule required as it is regular priority
	if(!faceUp->myDeck.empty()){	// Avoid Seg Faults
		if(currPlayer->getCard(cardSelect).getRank() >= faceUp->myDeck.back().getRank()){
			return true;
		}
	}
	return false;
}
//Manipulators////////////////////////////////////////////////////////////////////////////
ostream &operator <<(ostream &out, card &card){
	out << card.showRank();
	out << card.showSuit();
	return out;
}
//main////////////////////////////////////////////////////////////////////////////////////
int main()
{	
	bool cardValid = false;
	bool aBurnFlag = false;
	bool skippedFlag = false;
	bool deckEmpty;
	int aCardWidth = 7;
	int cardSelect = -1;
	int deckSize = 52;
	deck faceDown(deckSize);
	faceDown.generate();
	faceDown.shuffle();
	deck faceUp;
	vector<player> playerSet;
	playerSet.push_back(player(1));
	playerSet.push_back(player(2));
	int turnCount = -1;
	int turn = -1;	
	int numberOfPlayers = 2;	// Fixed to 2 1 player 1 CPU at present

	initialDeal(&(playerSet[0]),&(playerSet[1]),&faceDown);
	
	//int capture_me = 
	//cout << findCardSameRank(&(playerSet[0]),2);
	// /cout << capture_me << endl;
	
	// Turn
	// while p1hand OR p2hand not empty AND all cards are drawn from faceDown
	while(playerSet[0].hand.size() >  0 || playerSet[1].hand.size() >  0){ 
		++turnCount;	// Increment turn count
		turn = turnCount % numberOfPlayers;

		// Turn
		// Test to skip player
		// As soon as deck has a card and its an 8 keeps skipping 
		if(!faceUp.myDeck.empty()){						// If deck is not empty
			if(faceUp.myDeck.back().getRank() == 8 && skippedFlag == false){	// If top of faceUpDeck==8 >> skip
				cout << "skip" << endl;
				skippedFlag = true;
			}
			else{										// otherwise == If top of faceUpDeck!=8 >> turn
				cout << "Turn" << endl;
				displayFaceUp(&faceUp);
				sortHand(&(playerSet[turn]));
				displayHand(&(playerSet[turn]));
				//displayAllHands(&playerSet);	
				cardSelect = selectCard(&(playerSet[turn]));
				cardValid = validCard(&(playerSet[turn]),&faceUp,cardSelect,&aBurnFlag);
				
				if(cardValid){
					playCard(&(playerSet[turn]),&faceUp,cardSelect);
					draw(&playerSet[turn],&faceDown);		// draw() fx will cause while loop to exit once the last card is drawn
					cout << "draw()" << endl;
					cardValid = false;
				}else{
					collectPile(&(playerSet)[turn],&faceUp);
					cout << "You had to collectPile" << endl;
				}
				skippedFlag = false;	
			}	
		}
		else{	//if the deck is empty just perform/Allow a turn >> No tests required for 8
			cout << "Turn" << endl;
			displayFaceUp(&faceUp);	
			sortHand(&(playerSet[turn]));	
			displayHand(&(playerSet[turn]));	
			cardSelect = selectCard(&(playerSet[turn]));
			cardValid = validCard(&(playerSet[turn]),&faceUp,cardSelect,&aBurnFlag);
			
			if(cardValid){
				playCard(&(playerSet[turn]),&faceUp,cardSelect);
				draw(&playerSet[turn],&faceDown);		// draw() fx will cause while loop to exit once the last card is drawn
				cout << "draw()" << endl;
				cardValid = false;}
			else{
				collectPile(&(playerSet)[turn],&faceUp);
				cout << "You had to collectPile" << endl;
			}
		}
		// Burn baby burn disco inferno
		if(aBurnFlag){
			cout << "Ohh Burn" << endl;
			faceUp.myDeck.clear();			// Burn faceUp deck
			--turnCount;					// Decrement turn count so current play is same player next loop of while statement
			aBurnFlag = false;				// Reset Flag
		}
	}	
	if(!playerSet[0].getNumCards()){	// p0 has no cards left in hand AND no cards left in deck
			cout << "p0 wins" << endl;
			cout << "ctrl-c to exit" << endl;
	}
	if(!playerSet[1].getNumCards()){	// p1 no cards left in hand AND no cards left in deck
		cout << "p1 wins" << endl;
		cout << "ctrl-c to exit" << endl;
	}		
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////