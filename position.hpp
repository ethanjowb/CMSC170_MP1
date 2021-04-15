#include <iostream>

struct position{
    int x;
    int y;
};

position difference(position a, position b){
    position p;
    p.x = abs(a.x - b.x);
    p.y = abs(a.y - b.y);
    return p;
}