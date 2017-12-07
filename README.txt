Palace Card Game:
==========================
A card game using a standard playing deck.
Which can be played by 2 playe



+ 52 Card Deck is shuffled and referred to as the "face down deck".
+ 5 cards are dealt to each player from the face down deck.
+ Loop >> while both players have cards AND face down deck isn't empty
>> Current player prompted to choose a card to play to the face up deck.
>> Plays card
>> Draws card from face down deck and adds the card to players hand
>> If card selected to play cannot be played then that player must collect
>> the pile of face up cards

Playable Card:
===============
+ A Card that is higher in rank than the last played card in the face up deck 
+ OR if the card is a magic card which is playable depending on the card below.

Cards:
======
+ A - card with highest rank
+ 2 - Magic - Down to 2
+ 3 - Magic - Mirror
+ 4
+ 5
+ 6
+ 7 - Magic - Lower Than a 7
+ 8 - Magic - Skips
+ 9
+ 10 - Magic - Burns the deck
+ J
+ Q
+ K

"Magic" Cards:
============
+ 2 - Down to 2 - Lowers the rank back down to 2. Card can be played on any card.

+ 3 - Mirror - Mirrors the card below it onto next player.
	- If 3 played on A then the next player must play a card for the A.

+ 7 - Lower Than a 7 - Next card played must be lower than a 7 (6,5,4 OR Magic)
	- Priority swaps back to normal at end of that turn

+ 8 - Skips - Skips the player after you.

+ 10 - Burns the deck - Removes all cards from face up pile. Then player can play another card.

Misc. Rules:
============
If no cards in faceUp deck >> you can play any card >> any card valid
	
