
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
    //std::srand(time(0));
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

// int main () {

//     int num_players;
//     string name;
//     bettingRound card_deck;
//     vector <player> players; 

//     cout << "How many players are joining this round?: ";

//     cin >> num_players;
//     players.resize(num_players);

//     cout << "Enter player names in the order they are sitting." << endl;

//     for (int i = 0; i < num_players; i++) {
//         cout << "Player" << i+1 << ": ";
//         cin >> name;
//         players[i].set_name(name);        
//     }


// //     shuffle (cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));

// // card_deck.print();

// // card_deck.shuffle();
// // cout << endl; 
// // card_deck.print();


// //  for (size_t i = 0; i < 2; i++) {
// //     for(size_t j = 0; j < 3; j++) {  
// //         card_deck.deal(players.at(j).player_hand);
// //     }

// // }

// // // set<string>iterator:: itr; 
// // // set <string> s = p.at(0).player_hand;
// // // cout << s << endl; 

// //  cout << card_deck.cardDeck.size() << endl; 
// }





