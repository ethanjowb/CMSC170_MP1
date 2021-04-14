#include<iostream>
#include<vector>
#include"position.hpp"
#include"movements.hpp"

class puzzle{
    private:
        unsigned int board[3][3] = {{7,2,4},{5,0,6},{8,3,1}};
        position curPosition;
    private:
        void toggle(MOVEMENTS);
    public:
        puzzle();
        puzzle(position);
        ~puzzle(){}
        void move(MOVEMENTS);
        void printBoard();
        unsigned int getBoard();
};

puzzle::puzzle(){
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

