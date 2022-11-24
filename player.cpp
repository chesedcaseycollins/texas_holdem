#include <iostream>
#include <set>
#include "poker.h"

using namespace std;

player::player() {
    chips = 500;                        // Cash value.
    folded = false;                      // 0 if player folded 1 otherwise. 
    player_name = "";
};