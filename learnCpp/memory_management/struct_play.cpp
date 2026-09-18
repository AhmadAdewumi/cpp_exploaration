#include <iostream>

struct Player{
    int score;
    int level;
};

int main(){
    Player p1 = {100, 5};

    std::cout << "score is: " << p1.score << "\n";
    std::cout << "level is: " << p1.level << "\n";

    p1.score = 50;
    std::cout << "score is: " << p1.score << "\n";

    return 0;
}