#include<iostream>
#include<vector>

using namespace std;

struct axis{
    int x;
    int y;
};

class Board{
    public:
        vector< vector<int> > board;

    public:
        Board();
        Board(vector<int>, vector<int>, vector<int>);
        Board(vector< vector<int> >);
        ~Board();

    public:
        void printBoard();
        void toSwap(axis, axis);
        axis findEmpty();
        bool isSolved();
};

Board::Board(){
    //i row
    //j collumn
    int counter = 0;
    for(int i = 0; i < 3; i++){
        vector<int> row;
        for(int j = 0; j < 3; j++){
            row.push_back(counter);
            counter++;
        }
        this->board.push_back(row);
    }
}

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
    	vector<int> row;
        for(int j = 0; j < 3; j++){
            row.push_back(other[i][j]);
        }
        this->board.push_back(row);
    }
}

Board::~Board(){
    for(int i = 0; i < 3; i++){
        this->board[i].clear();
    }
    this->board.clear();
}

void Board::printBoard(){
    cout << "\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->board[i][j] == 0)
                cout << "  ";
            else
                cout << this->board[i][j] << " ";
        }
        cout << "\n";
    }
}

 void Board::toSwap(axis fromPosition, axis toPosition){
     // this.board[y][x]
     int temp = this->board[fromPosition.y][fromPosition.x];
     this->board[fromPosition.y][fromPosition.x] = this->board[toPosition.y][toPosition.x];
     this->board[toPosition.y][toPosition.x] = temp;
 }

 axis Board::findEmpty(){
     axis loc;
     for(int i = 0; i < 3; i++){
         for(int j = 0; j < 3; j++){
             if(this->board[i][j] == 0){
                 loc.x = j;
                 loc.y = i;
                 return loc;
             }
         }
     }
 }

bool Board::isSolved(){
    Board goal;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->board[i][j] != goal.board[i][j]){
                return false;
            }
        }
    }
    return true;
}
