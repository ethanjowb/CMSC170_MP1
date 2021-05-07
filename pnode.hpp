#include<iostream>
#include<vector>
#include"puzzle.hpp"
#include"position.hpp"

class pnode{
    public:
        pnode* parent;
        puzzle* p;
        std::vector<pnode> children;
        bool seen;
        int height;
        int cost; // cost + height
    public:
        pnode();
        pnode(pnode &obj);
        ~pnode(){}
        void solveCost();
        void hasSeen();
        bool isSolved();
};

pnode::pnode(){
    this->parent = NULL;
    this->p = NULL;
    this->height = 0;
    this->cost = 0;
    this->seen = false;
}

pnode::pnode(pnode &obj){
    this->parent = obj.parent;
    this->p = obj.p;
    this->seen = obj.seen;
    this->height = obj.height;
    this->cost = obj.cost;
    for(auto i:obj.children){
        this->children.push_back(i);
    }
}

void pnode::solveCost(){
    std::vector<std::vector<int>> nodeBoard = this->p->getBoard();
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

void pnode::hasSeen(){
    this->seen = true;
}

bool pnode::isSolved(){
    return this->p->isSolved();
}