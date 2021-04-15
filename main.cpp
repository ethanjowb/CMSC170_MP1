#include <iostream>
#include <array>
#include "position.hpp"

int main(){
    std::array<std::array<int, 3>,3> a;
    a[0] = {1,2,3};
    a[1] = {4,5,6};
    a[2] = {7,8,9};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << a[j][i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}