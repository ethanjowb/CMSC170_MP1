#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include"pnode.hpp"
#include"puzzle.hpp"
    
class controller{
    private:
        pnode initial;
        std::vector<pnode> q;
    public:
        controller(){
            this->initial = pnode();
            puzzle *px = new puzzle();
            this->initial.p->changeBoard(px->getBoard());
        }
        void solve();
        bool compare(pnode a,pnode b){
            return a.cost < b.cost;
        }
};



void controller::solve(){
    // changes initial node state to seen then sent to the queue
    initial.hasSeen();
    q.push_back(initial);
    while(q.size() != 0){
        std::sort(q.begin(), q.end(),compare);
        pnode p = q.front();
        q.pop_back();
        std::vector<puzzle> pz = p.p->move();

        // if(p.isSolved()){
        //     std::vector<pnode> pn;
        //     while(p.parent != NULL){ 
        //         pn.insert(pn.begin(),p);
        //         p = p.parent;
        //     }
        // }
        // for(int i = 0; i < pz.size(); i++){
        //     pnode node = pnode(&p,pz[i],p.getHeight() + 1);
        //     if(!node.isSeen()){
        //         node.hasSeen();
        //         store.push_back(node);
        //     }
        // }
    }
}