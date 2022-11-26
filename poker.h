
/********************************************************************************************************************************************************
    Maria Hernandez 
    COSC202
    11/01/2022
    poker.h
    The whole project will simulate a poker Texas Holdem game. In this .h file, we develop the interface for the bettingRound class, 
    which sets up the card deck in every round of the game, and the player class which contains the player's information -
    name, hand, etc.
***********************************************************************************************************************************************************/

#include <vector>
#include <string>
#include <set>

using namespace std; 

class player {
    int chips;                        // Cash value.
    bool folded;                      // 0 if player folded 1 otherwise. 
    string player_name;     
    set <string> player_hand;         // Hand of the player.
    int in_pot;
    int player_bet;
public:
    player();
    void set_name(string);
    void chip_change(int);
    void add_card(string);
    void print_hand();
    int num_chips();
    void bet(int);
};


class bettingRound {
    vector<string> CARD_SUITS;      // Heart Diamond Club Spade.
    vector<string> CARD_VALUES;     // A 2 - 10 J Q K.
    vector <string> cardDeck;       // 52 value-suit cards.
    vector <int> pot;

    public:
        bettingRound();             // Constructor will use a nested for-loop to loop through CARD_SUITS and CARD_VALUES to obtain 52 value-suit cards.
        void shuffle();             // Suffle the cards in a random order using the random_shuffle() method of the <algorithm> library of the STL.
        string deal();              // Deal one card to a player and decrease the card deck by one each time it hands a card. 
        string handHierarchy(vector <player>);  // Determines the hand each player has, call the compareHands() method and returns the winner.
        int compareHands(vector<vector <int>>); // Compare players' hands using a vector of integers of size ten - each element corresponds to one of the ten cases (flush straight, straight, etc.)
                                                // ranging left to right from the hand that is worth the least to the one that is worth the most. Function returns the index of the player that won. 
        void print();
        void raise(int);
        void fold();
        void call();
        void blinds(player, player);
};