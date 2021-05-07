#include<iostream>
#include<vector>
#include"position.hpp"

class puzzle{
    public:
        std::vector<std::vector<int>> board = {{7,2,4},{5,0,6},{8,3,1}};
        position curPosition;
        std::vector<puzzle> children;
    public:
        puzzle();
        puzzle(std::vector<std::vector<int>>);
        ~puzzle();
        puzzle createMove(int, int);
        void printBoard();
        bool isSolved();
        void changeBoard(std::vector<std::vector<int>>);
        std::vector<std::vector<int>> getBoard();
        std::vector<puzzle> move();
        void toggle(int, int);
        puzzle& operator = (const puzzle& p){\
            if(this == &p)
                return *this;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    this->board[j][i] = p.board[j][i];
                }
            }
            this->curPosition.x = p.curPosition.x;
            this->curPosition.y = p.curPosition.y;
            return *this;
        }
};

puzzle::puzzle(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[j][i] == 0){
                this->curPosition.x = j;
                this->curPosition.y = i;
            }
        }
    }
}

puzzle::puzzle(std::vector<std::vector<int>> b){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->board[j][i] = b[j][i];
            if(b[j][i] == 0){
                this->curPosition.x = b[j][i];
                this->curPosition.y = b[j][i];
            }
        }
    }
}

puzzle::~puzzle(){
    for(int j = 0; j < this->children.size(); j++){
        delete &(this->children[j]);
    }
    this->children.clear();
    this->children.clear();
    for(int i = 0; i < 3; i++){
        this->board[i].clear();
    }
    this->board.clear();
}

puzzle puzzle::createMove(int x, int y){
    puzzle *p = new puzzle(this->board);
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

    for(int j = 0; j < 4; j++){
        if((this->curPosition.x + movements[0][j] >= 0 && this->curPosition.x + movements[0][j] <= 2) && (this->curPosition.y + movements[1][j] >= 0 && this->curPosition.y + movements[1][j] <= 2)){
            this->children.push_back(this->createMove(movements[0][j],movements[1][j]));
        }
    }
    return this->children;
}

void puzzle::toggle(int x, int y){
    this->board[this->curPosition.x][this->curPosition.y] = this->board[this->curPosition.x + x][this->curPosition.y + y];
    this->board[this->curPosition.x + x][this->curPosition.y + y] = 0;
    this->curPosition.x = this->curPosition.x + x;
    this->curPosition.y = this->curPosition.y + y;
}

