#include<iostream>
#include<vector>
#include"position.hpp"

using namespace std;

class Board{
    public:
        vector< vector<int> > board;

    public:
        Board(vector<int>, vector<int>, vector<int>);
        Board(vector< vector<int> >);
        ~Board(){}

    public:
        void setBoard(vector< vector<int> >);
        void printBoard();
        void toSwap(axis fromPosition, axis toPosition){
            // this.board[y][x]
            int temp = this->board[fromPosition.y][fromPosition.x];
            this->board[fromPosition.y][fromPosition.x] = this->board[toPosition.y][toPosition.x];
            this->board[toPosition.y][toPosition.x] = temp;
        }

};

Board::Board(vector<int> row1, vector<int> row2, vector<int> row3){
    this->board.push_back(row1);
    this->board.push_back(row2);
    this->board.push_back(row3);
    // cout << "initialized";
}

Board::Board(vector< vector<int> > other){
    //i row
    //j collumn
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->board[i][j] = other[i][j];
        }
    }
}

void Board::setBoard(vector< vector<int> > other){
    //i row
    //j collumn
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->board[i][j] = other[i][j];
        }
    }
}

void Board::printBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << this->board[i][j] << " ";
        }
        cout << "\n";
    }
}

// void Board::toSwap(axis fromPosition, axis toPosition){
//     // this.board[y][x]
//     int temp = this->board[fromPosition.y][fromPosition.x];
//     this->board[fromPosition.y][fromPosition.x] = this->board[toPosition.y][toPosition.x];
//     this->board[toPosition.y][toPosition.x] = temp;
// }
