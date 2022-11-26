#include <iostream> 
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include "poker.cpp"

int main () {

    int num_players, round_count = 0;
    string name, card;
    bettingRound card_deck;
    vector <player> players; 

    cout << "How many players are joining this round?: ";

    cin >> num_players;
    players.resize(num_players);

    cout << "Enter player names in the order they are sitting." << endl;
    while (num_players > 1) {
        for (int i = 0; i < num_players; i++) {
            cout << "Player" << i+1 << ": ";
            cin >> name;
            players[i].set_name(name);        
        }

        card_deck.shuffle();
        card_deck.blinds(players[round_count % num_players], players[(round_count+1) % num_players]);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < num_players; j++) {
                players[j].add_card(card_deck.deal());
            }
        }

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }

        for (int i = 0; i < 3; i++) {
            card = card_deck.deal();
            for (int i = 0; i < num_players; i++) {
                players[i].add_card(card);
            }            
        }

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }
        
        card = card_deck.deal();
        for (int i = 0; i < num_players; i++) {
            players[i].add_card(card);
        }  

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }
        
        card = card_deck.deal();
        for (int i = 0; i < num_players; i++) {
            players[i].add_card(card);
        }  

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }

    round_count++;

    }
 
    return 0;

}





