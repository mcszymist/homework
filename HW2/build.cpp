#include "build.hpp"
using std::size_t;
#include <iostream>
using std::cout;
using std::endl;
int build(int w, int e, const vector<Bridge> &bridges){
    vector<int> stack{};
    int max = 0;
    size_t counter = 0;
    while(true){
        bool bIsValid = true;
        if(counter>=bridges.size()){
            if(stack.size() == 0)
                break;
                
            int temp = 0;
            for(auto ii : stack){
                temp += bridges[ii][2];
            }
            if(max < temp){
                max = temp;
            }
            counter = stack.back()+1;
            stack.pop_back();
        }
        else
        {
            for(auto ii : stack){
                if(((bridges[counter][0] <= bridges[ii][0] && bridges[counter][1] >= bridges[ii][1]) || (bridges[counter][0] >= bridges[ii][0] && bridges[counter][1] <= bridges[ii][1]))){
                    bIsValid = false;
                }
            }
            if(bIsValid == true){
                stack.push_back(counter);
            }
            ++counter;
        }
    }
    return max;
}
