#include "startGame.c"
int main() {
    system("color 02");
    while(1) { 
        mainManu();
        startGame();
        overInfo(); 
    }
}