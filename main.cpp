#include"controller.hpp"

using namespace std;

void printVector(vector<int>);

int main(){

    vector<int> row1;
    row1.push_back(7);
    row1.push_back(2);
    row1.push_back(4);
    vector<int> row2;
    row2.push_back(5);
    row2.push_back(0);
    row2.push_back(6);
    vector<int> row3;
    row3.push_back(8);
    row3.push_back(3);
    row3.push_back(1);

    Board b(row1,row2,row3);
    Node n(b);
    Controller c;

    c.solve(n);
    c.printSolution();

    return 0;
} 

    // vector<int> a;
    // vector<int> b;
    // vector<int> c;

    // for(int i = 0; i < 9; i++){
    //     if(i < 3)
    //         a.push_back(i);
    //     else if(i >= 3 && i < 6)
    //         b.push_back(i);
    //     else
    //         c.push_back(i);
    // }

    // // // swapping stuff
    // // int from = 0;
    // // int to = 2;
    // // int temp = a[from];
    // // int temp1 = a[to];
    // // a.erase(a.begin() + from);
    // // a.insert(a.begin() + from, temp1);
    // // a.erase(a.begin() + to);
    // // a.insert(a.begin() + to, temp);
    // // for(int i = 0; i < 3; i++){
    // //     cout << a[i] << " ";
    // // }

    // cout << "Size: " << a.size() << "\n";
    // Board sample(a,b,c);
    // // sample.printBoard();

    // Board sample1(sample.board);

    // axis p,q;
    // p.x = 0;
    // p.y = 0;
    // q.x = 1;
    // q.y = 1;

    // sample1.toSwap(p,q);
    // // sample1.printBoard();

    // Node n(sample1);
    // n.create(&n);
    // n.printNode();

    // Node m(&n);
    // m.printNode();
