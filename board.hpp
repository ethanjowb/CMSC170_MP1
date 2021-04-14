#include<iostream>
#include<vector>

class puzzle{
    private:
        unsigned int board[9];
        std::vector<std::vector<int>> combi;
    public:
        puzzle();
        ~puzzle();
        void toggle(unsigned int, unsigned int);
        

};