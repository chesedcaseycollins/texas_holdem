
// Chesed Collins and Maria Hernandez

#include <iostream> 
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include "poker.h"
#include <ctime>

using namespace std; 

player::player() {
    chips = 500;                        // Cash value.
    folded = false;                      // 0 if player folded 1 otherwise. 
    player_name = "";
    player_bet = 0;
};

void player::set_name(string name) {
    player_name = name;
}

void player::chip_change(int change) {
    chips += change;
}

void player::add_card(string card) {
    player_hand.insert(card);
}

void player::print_hand() {
    set<string>::iterator it;
    for (it = player_hand.begin(); it!= player_hand.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void player::bet(int bet_amt) {
    chips -= bet_amt;
    player_bet += bet_amt;
}

void player::print_name() {
    cout << player_name;
}

bettingRound::bettingRound() {

    CARD_SUITS = { 
        "H", "C", "D", "S" 
    };

    CARD_VALUES = { 
        "A", "2", "3", "4", "5", "6", "7", 
        "8", "9", "10", "J", "Q", "K" 
    };

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            cardDeck.push_back(CARD_VALUES.at(i) + CARD_SUITS.at(j));
        }
    }
}

void bettingRound::shuffle() {
    std::srand(time(0));
    std::random_shuffle(cardDeck.begin(), cardDeck.end()); 
}

void bettingRound::print() {
    for (size_t i = 0; i != cardDeck.size(); i++) {
        cout << cardDeck[i] << endl; 
    }
}

string bettingRound::deal() {
    // cardDeck.pop_back();
    string card = cardDeck.at(cardDeck.size()-1);
    cardDeck.pop_back();
    return card;
}

void bettingRound::blinds(int size, int &small_i, int &big_i, int &dealer_i) {
    big_i = small_i;
    small_i = (small_i + 1) % size;

    if (big_i == 0) dealer_i = size - 1;
    else dealer_i = big_i - 1;
}