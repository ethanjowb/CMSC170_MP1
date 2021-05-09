#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include"board.hpp"

using namespace std;

int main(){
    vector<int> a;
    vector<int> b;
    vector<int> c;

    for(int i = 0; i < 9; i++){
        if(i < 3)
            a.push_back(i);
        else if(i >= 3 && i < 6)
            b.push_back(i);
        else
            c.push_back(i);
    }

    Board sample(a,b,c);
    sample.printBoard();

    Board sample1(sample.board);

    axis p,q;
    p.x = 0;
    p.y = 0;
    q.x = 1;
    q.y = 1;

    sample1.toSwap(p,q);
    sample1.printBoard();

    return 0;
}