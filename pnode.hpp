#include<iostream>
#include<vector>
#include"puzzle.hpp"
#include"position.hpp"

class pnode{
    public:
        pnode* parent;
    private:
        puzzle p;
        std::vector<pnode> children;
        int height;
        bool seen;
        int cost; // cost + height
    public:
        pnode();
        pnode(pnode*,puzzle, int);
        ~pnode(){}
        void solveCost();
        int getCost();
        puzzle getPuzzle();
        int getHeight();
        void hasSeen();
        bool isSeen();
        bool compare(pnode, pnode);
        bool isSolved();
};

pnode::pnode(){
    this->parent = NULL;
    this->height = 0;
    this->cost = 0;
    this->seen = false;
}

pnode::pnode(pnode* pn, puzzle p, int h){
    this->parent = pn;
    this->p = p;
    this->height = pn->getHeight() + 1;
    this->cost = 0;
}

pnode::~pnode(){
    delete[] parent;
}

void pnode::solveCost(){
    std::vector<std::vector<int>> nodeBoard = this->p.getBoard();
    std::vector<std::vector<int>> goalBoard = {{0,1,2},{3,4,5},{6,7,8}};
    for(int ny = 0; ny < 3; ny++){
        for(int nx = 0; nx < 3; nx++){
            if(nodeBoard[nx][ny] != 0){
                for(int gy = 0; gy < 3; gy++){
                    for(int gx = 0; gx < 3; gx++){
                        if(nodeBoard[nx][ny] == goalBoard[gx][gy]){
                            position nb, gb;
                            nb.x = nx;
                            nb.y = ny;
                            gb.x = gx;
                            gb.y = gy;
                            this->cost = difference(nb,gb);
                        }
                    }
                }
            }
        }
    }
}

puzzle pnode::getPuzzle(){
    return this->p;
}

int pnode::getCost(){
    return this->cost + this->height;
}

int pnode::getHeight(){
    return this->height;
}

void pnode::hasSeen(){
    this->seen = true;
}

bool pnode::isSolved(){
    return this->getPuzzle().isSolved();
}

bool pnode::isSeen(){
    return this->seen;
}