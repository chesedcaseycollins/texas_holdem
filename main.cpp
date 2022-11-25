#include <iostream> 
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include "poker.cpp"

int main () {

    int num_players;
    string name;
    bettingRound card_deck;
    vector <player> players; 

    cout << "How many players are joining this round?: ";

    cin >> num_players;
    players.resize(num_players);

    cout << "Enter player names in the order they are sitting." << endl;

    for (int i = 0; i < num_players; i++) {
        cout << "Player" << i+1 << ": ";
        cin >> name;
        players[i].set_name(name);        
    }

    card_deck.shuffle();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < num_players; j++) {
            players[j].add_card(card_deck.deal());
        }
    }

    for (int j = 0; j < num_players; j++) {
        players[j].print_hand();
    }
 
    return 0;

}





