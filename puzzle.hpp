#include<iostream>
#include"position.hpp"
#include"movements.hpp"

class puzzle{
    private:
        int** board = 0;
        position curPosition;
    private:
        void toggle(MOVEMENTS);
    public:
        puzzle();
        puzzle(position);
        ~puzzle(){}
        void move(MOVEMENTS);
        void printBoard();
        int** getBoard();
};

puzzle::puzzle(){
    this->board = new int*[3];
    for(int h = 0; h < 3; h++){
        this->board[h] = new int[3];
        for(int w = 0; w < 3; w++){
            this->board[w][h] = 0;
        }
    }
    this->board[]
    this->curPosition.x = 1;
    this->curPosition.y = 1;
}

puzzle::puzzle(position p){
    this->curPosition.x = p.x;
    this->curPosition.y = p.y;
}

void puzzle::toggle(MOVEMENTS m){
    switch(m){
        case MOVEMENTS::LEFT:
            board[this->curPosition.x][this->curPosition.y] = board[this->curPosition.x + 1][this->curPosition.y];
            board[this->curPosition.x + 1][this->curPosition.y] = 0;
            this->curPosition.x++;
        break;
        case MOVEMENTS::RIGHT:
            board[this->curPosition.x][this->curPosition.y] = board[this->curPosition.x - 1][this->curPosition.y];
            board[this->curPosition.x - 1][this->curPosition.y] = 0;
            this->curPosition.x--;
        break;
        case MOVEMENTS::UP:
            board[this->curPosition.x][this->curPosition.y] = board[this->curPosition.x][this->curPosition.y + 1];
            board[this->curPosition.x][this->curPosition.y + 1] = 0;
            this->curPosition.y++;
        break;
        case MOVEMENTS::DOWN:
            board[this->curPosition.x][this->curPosition.y] = board[this->curPosition.x][this->curPosition.y - 1];
            board[this->curPosition.x][this->curPosition.y - 1] = 0;
            this->curPosition.y--;
        break;
    }
}

void puzzle::move(MOVEMENTS m){
    if((m == MOVEMENTS::LEFT) && this->curPosition.x > 0){
        this->toggle(m);
    }
    else if((m == MOVEMENTS::RIGHT) && this->curPosition.x < 2){
        this->toggle(m);
    }
    else if((m == MOVEMENTS::UP) && this->curPosition.y > 0){
        this->toggle(m);
    }
    else if((m == MOVEMENTS::DOWN) && this->curPosition.y < 2){
        this->toggle(m);
    }
}

void puzzle::printBoard(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            std::cout << this->board[j][i] << " ";
        std::cout << "\n";
}

int** puzzle::getBoard(){
    return board;
}