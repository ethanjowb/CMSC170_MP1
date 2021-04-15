#include<iostream>
#include<vector>
#include"position.hpp"

class puzzle{
    private:
        std::vector<std::vector<int>> board = {{7,2,4},{5,0,6},{8,3,1}};
        position curPosition;
    public:
        puzzle();
        ~puzzle();
        puzzle createMove(int, int);
        void printBoard();
        bool isSolved();
        void changeBoard(std::vector<std::vector<int>>);
        std::vector<std::vector<int>> getBoard();
        std::vector<puzzle> move();
        void toggle(int, int);
};

puzzle::puzzle(){
    this->curPosition.x = 1;
    this->curPosition.y = 1;
}

puzzle::~puzzle(){
}

puzzle puzzle::createMove(int x, int y){
    puzzle *p = new puzzle();
    p->changeBoard(this->board);
    p->toggle(x,y);
    return *p;
}

void puzzle::changeBoard(std::vector<std::vector<int>> b){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            this->board[j][i] = b[j][i];
            if(b[j][i] == 0){
                this->curPosition.x = j;
                this->curPosition.y = i;
            }
        }
    }
}

void puzzle::printBoard(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            std::cout << this->board[j][i] << " ";
        std::cout << "\n";
}

std::vector<std::vector<int>> puzzle::getBoard(){
    return board;
}

bool puzzle::isSolved(){
    int counter = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->board[j][i] != counter++)
                return false;
        }
    }
    return true;
}

std::vector<puzzle> puzzle::move(){
    int movements[2][4] = {{1,-1,0,0},{0,0,1,-1}};
    std::vector<puzzle> p;

    for(int j = 0; j < 4; j++){
        if((this->curPosition.x + movements[0][j] >= 0 && this->curPosition.x + movements[0][j] <= 2) && (this->curPosition.y + movements[1][j] >= 0 && this->curPosition.y + movements[1][j] <= 2)){
            p.push_back(this->createMove(movements[0][j],movements[1][j]));
        }
    }
    return p;
}

void puzzle::toggle(int x, int y){
    this->board[this->curPosition.x][this->curPosition.y] = this->board[this->curPosition.x + x][this->curPosition.y + y];
    this->board[this->curPosition.x + x][this->curPosition.y + y] = 0;
    this->curPosition.x = this->curPosition.x + x;
    this->curPosition.y = this->curPosition.y + y;
}