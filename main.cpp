#include"controller.hpp"

using namespace std;

void given();
void custom();

int main(){
    int choice;

    cout << "What type: \n" << "(1) CUSTOM\n(2) GIVEN\nANSWER: " ;
    cin >> choice;
    
    choice == 1 ? custom() : given();

    return 0;
} 

void custom(){
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;

    int a;

    for(int i = 0; i < 9; i++){
        cin >> a;
        if(i <= 2){
            row1.push_back(a);
        }
        else if(i <= 5){
            row2.push_back(a);
        }
        else{
            row3.push_back(a);
        }
    }

    Board b(row1,row2,row3);
    Node n(b);
    Controller c;

    c.solve(n);
    // cout << "FINISHED:\n";
    // c.goal->printBoard();
    // c.goal->parent->printBoard();
    c.printSolution();
}

void given(){
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
}