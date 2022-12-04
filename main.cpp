#include <iostream> 
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include "poker.cpp"

int main () {

    int num_players, round_count = 0, small_i = 0, big_i = 0, dealer_i = 0, k;
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
        card_deck.blinds(num_players, small_i, big_i, dealer_i);
        players[big_i].bet(10);
        players[small_i].bet(5);

        for (int i = 0; i < 2; i++) {
            k = 0;
            for (int j = 0; j < num_players; j++) {
                if (j + dealer_i < num_players) players[j + dealer_i].add_card(card_deck.deal());
                else {
                    players[k].add_card(card_deck.deal());
                    k++;
                }
            }
        }

        card_deck.blinds(num_players, small_i, big_i, dealer_i);
        players[dealer_i].print_name();
        cout << endl;
        players[big_i].print_name();
        cout << endl;
        players[small_i].print_name();
        cout << endl;

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }

        for (int i = 0; i < 3; i++) {
            card = card_deck.deal();
            for (int i = 0; i < num_players; i++) {
                players[i].add_card(card);
            }            
        }

        card_deck.blinds(num_players, small_i, big_i, dealer_i);
        players[dealer_i].print_name();
        cout << endl;
        players[big_i].print_name();
        cout << endl;
        players[small_i].print_name();
        cout << endl;

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }
        
        card = card_deck.deal();
        for (int i = 0; i < num_players; i++) {
            players[i].add_card(card);
        }  

        card_deck.blinds(num_players, small_i, big_i, dealer_i);
        players[dealer_i].print_name();
        cout << endl;
        players[big_i].print_name();
        cout << endl;
        players[small_i].print_name();
        cout << endl;

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }
        
        card = card_deck.deal();
        for (int i = 0; i < num_players; i++) {
            players[i].add_card(card);
        }  

        card_deck.blinds(num_players, small_i, big_i, dealer_i);
        players[dealer_i].print_name();
        cout << endl;
        players[big_i].print_name();
        cout << endl;
        players[small_i].print_name();
        cout << endl;

        for (int i = 0; i < num_players; i++) {
            players[i].print_hand();
        }

    round_count++;

    }
 
    return 0;

}





