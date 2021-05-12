#include"controller.hpp"

using namespace std;

// void swap(vector<int>*, int, int);
// void printVector(vector<int>);

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

// void swap(vector<int> *value, int from, int to){
//     int fromNode = (*value)[from];
//     int toNode = (*value)[to];
//     (*value).erase((*value).begin() + from);
//     (*value).insert((*value).begin() + from, toNode);
//     (*value).erase((*value).begin() + to);
//     (*value).insert((*value).begin() + to, fromNode);
// }


// void printVector(vector<int> value){
//     for(int i = 0; i < value.size(); i++){
//         cout << value[i] << " ";
//     }
//     cout << "\n";
// }


    // vector<int> a;

    // while(true){
    //     int b;
    //     cin >> b;
    //     if(b != 0){
    //         a.push_back(b);
    //     }
    //     else{
    //         break;
    //     }
    // }

    // bool changed = false;
    // while(true){
    //     int smol = a[0];
    //     for(int j = 0; j < a.size(); j++){
    //         if(smol < a[j]){
    //             swap(&a, j-1, j);
    //             cout << "SMOL: " << smol << "\n";
    //             changed = true;
    //         }
    //         else{
    //             smol = a[j];
    //         }
    //         printVector(a);
    //     }
    //     if(changed){
    //         changed = false;
    //         smol = a[0];
    //     }
    //     else{
    //         break;
    //     }
    // }

    // // printVector(a);