// Playing Deck of Cards (52)
// There are 3 aspects of a card: face value, shape, color
// Face Value: 1(A), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11(J), 12(Q), 13(K)
// Shape: 0(Club), 1(Spade), 3(Diamond), 4(Heart)
// Color: 0(Black), 1(Red)

#include <iostream>
using namespace std;

struct card {
    int face;
    int shape;
    int color;
};

int main () {

    // Decalaring a structure variable
    struct card c;
    c.face = 1; // A
    c.shape = 0; // Club
    c.color = 0; // Black


    struct card deck[52];   // An array of structures containing 52 cards
    deck[0] = {1, 0, 0};
    printf("%d ", deck[0].face);
    printf("%d ", deck[0].shape);
    printf("%d ", deck[0].color);

    return 0;
}