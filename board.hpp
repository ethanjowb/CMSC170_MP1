#include<iostream>
#include<vector>

enum class MOVEMENTS{LEFT, RIGHT, UP, DOWN};

class puzzle{
    private:
        unsigned int board[9] = {7,2,4,5,0,6,8,3,1};
        unsigned int curPosition = 4;
        std::vector<std::vector<int>> combi;
    private:
        void toggle(MOVEMENTS);
    public:
        puzzle(){}
        ~puzzle(){}
        void printBoard();
        void store(std::vector<int>);
};

void puzzle::toggle(MOVEMENTS m){
    switch(m){
        case MOVEMENTS::LEFT:
            board[this->curPosition] = board[this->curPosition + 1];
            board[this->curPosition + 1] = 0;
            this->curPosition++;
        break;
        case MOVEMENTS::RIGHT:
            board[this->curPosition] = board[this->curPosition - 1];
            board[this->curPosition - 1] = 0;
            this->curPosition--;
        break;
        case MOVEMENTS::UP:
            board[this->curPosition] = board[this->curPosition + 3];
            board[this->curPosition + 3] = 0;
            this->curPosition+=3;
        break;
        case MOVEMENTS::DOWN:
            board[this->curPosition] = board[this->curPosition - 3];
            board[this->curPosition - 3] = 0;
            this->curPosition-=3;
        break;
    }
}