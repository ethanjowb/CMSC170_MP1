#include <iostream>

struct position{
    int x;
    int y;
};

int difference(position a, position b){
    int steps = 0;
    steps += abs(a.x - b.x);
    steps += abs(a.y - b.y);
    return steps;
}