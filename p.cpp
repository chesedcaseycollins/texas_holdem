#include <iostream> 
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine

using namespace std; 

class round1 {
    vector <string> cardDeck;
    vector<string> CARD_SUITS;
    vector<string> CARD_VALUES;

    public:
    round1(); // Constructor, initializes cardDeck.
    void shuffle();
    void print(); 
    void deal(set <string>&); 

    // friend class player;
};

class player {
    private:
    set <string> player_hand; 
    // friend class round1; 
};

round1::round1() {

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

void round1::shuffle() {
    std::random_shuffle(&cardDeck[0], &cardDeck[cardDeck.size()]); 
}

void round1::print() {
    for (size_t i = 0; i != cardDeck.size(); i++) {
        cout << cardDeck[i] << endl; 
    }
}

void round1::deal(set <string> &player_hand) {
    // cardDeck.pop_back();
    player_hand.insert(cardDeck.at(cardDeck.size()-1));
    cardDeck.pop_back();
}

int main () {
    round1 cd;
    vector <player> p; 
    p.resize(3);

//     shuffle (cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));

cd.print();

cd.shuffle();
cout << endl; 
cd.print();


 for (size_t i = 0; i < 2; i++) {
    for(size_t j = 0; j < 3; j++) {  
        cd.deal(p.at(j).player_hand);

    }

}

// set<string>iterator:: itr; 
// set <string> s = p.at(0).player_hand;
// cout << s << endl; 

 cout << cd.cardDeck.size() << endl; 
}





