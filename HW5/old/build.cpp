#include "build.hpp"
using std::size_t;
#include <iostream>
using std::cout;
using std::endl;
#include <utility>
using std::pair;
using std::make_pair;
#include <cmath>
using std::round;
void cleanBridges(vector<Bridge> &stack){
    for(size_t i = 0;i<stack.size();i++){
        for(size_t ii = i;ii< stack.size();) {
            if (stack[i][0] == stack[ii][0] && stack[i][1] == stack[ii][1] && !i==ii) {
                if (stack[i][2] < stack[ii][2]) {
                    stack[i][2] = stack[ii][2];
                }
                stack.erase(stack.begin()+ii);
            }
            else{
                ii++;
            }
        }
    }
}
void addNullified(vector<Bridge> &stack){
    for(size_t i = 0;i<stack.size();i++){
        int nullMax = 0;
        int counter = 0;
        for(size_t ii = 0;ii< stack.size();ii++){
            if(i != ii){
                //nullified
                if((stack[i][0] >= stack[ii][0] && stack[i][1] <= stack[ii][1]) || (stack[i][0] <= stack[ii][0] && stack[i][1] >= stack[ii][1])){
                    nullMax += stack[ii][2];
                    counter++;
                }
            }
        }
        if(counter != 0) {
            nullMax = stack[i][2] - round(nullMax / counter);
        }
        else
        {
            nullMax = stack[i][2] - nullMax;
        }
        stack[i].push_back(nullMax);
    }
}

int build(int w, int e, const vector<Bridge> &bridges){
    if(bridges.size()==0){
        return 0;
    }
    vector<Bridge> stack = bridges;
    cleanBridges(stack);
    addNullified(stack);
    int max = 0;

    while(true){
        int pos = -1;
        int holdMax = -214748364;
        //Finding best bridge
        for(size_t i = 0;i<stack.size();i++){
            if(holdMax < stack[i][3]){
                holdMax = stack[i][3];
                pos = i;
            } else if(holdMax == stack[i][3] && stack[i][2] > stack[pos][2]){
                holdMax = stack[i][3];
                pos = i;
            }
        }
        if(pos == -1){
            break;
        }
        max += stack[pos][2];

        //remove nullified bridges
        for(size_t ii = 0;ii< stack.size();ii++){
            if(pos != ii){
                //nullified
                if((stack[pos][0] >= stack[ii][0] && stack[pos][1] <= stack[ii][1]) || (stack[pos][0] <= stack[ii][0] && stack[pos][1] >= stack[ii][1])){
                    stack.erase(stack.begin()+ii);
                    if(pos >= ii){
                        pos--;
                    }
                    ii--;
                }
            }
        }
        stack.erase(stack.begin() + pos);
    }
    return max;
}
