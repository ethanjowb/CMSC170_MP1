#include<iostream>
#include<vector>
#include<algorithm>
#include"pnode.hpp"
#include"puzzle.hpp"

bool compare(pnode a, pnode b){
    return a.getCost() < b.getCost();
}

class controller{
    private:
        pnode initial;
    public:
        controller(){}
        ~controller(){}
        std::vector<pnode> solve();
};

std::vector<pnode> controller::solve(){
    std::vector<pnode> store;
    initial.hasSeen();
    store.push_back(initial);
    while(store.size() != 0){
        std::sort(store.begin(),store.end(),compare);
        pnode p = store.at(store.begin());
        store.pop_back();
        puzzle puz = p.getPuzzle();
        std::vector<puzzle> pz = puz.move();

        if(p.isSolved()){
            std::vector<pnode> pn;
            while(p.parent != NULL){
                pn.insert(pn.begin(),p);
                p = p.parent;
            }
            return pn;
        }
        for(int i = 0; i < pz.size(); i++){
            pnode node = pnode(&p,pz[i],p.getHeight() + 1);
            if(!node.isSeen()){
                node.hasSeen();
                store.push_back(node);
            }
        }
    }
    return NULL;
}