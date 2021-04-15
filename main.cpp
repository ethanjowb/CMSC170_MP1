#include<iostream>
#include<vector>
#include"position.hpp"
#include"controller.hpp"
#include"pnode.hpp"
#include"puzzle.hpp"

int main(){
    controller c;
    std::vector<pnode> ans = c.solve();
    

    
    return 0;
}