//
// Created by mcszy on 11/18/2018.
//
#include "build.hpp"
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

bool compare(Bridge &a, Bridge &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}
void removeDups(vector<Bridge> &bridges){
    for(auto i = 1; i < bridges.size();i++){
        if(bridges[i-1][0] == bridges[i][0] && bridges[i-1][1] == bridges[i][1]){
            if(bridges[i-1][2] < bridges[i][2]){
                bridges.erase(bridges.begin()+i-1);
            }
            else{
                bridges.erase(bridges.begin()+i);
            }
            i--;
        }
    }
}

vector<Bridge> validBridges(Bridge selected,const vector<Bridge> &bridges){
    vector<Bridge> valid{};
    for(size_t ii = 0;ii< bridges.size();ii++){
        if(!((selected[0] >= bridges[ii][0] && selected[1] <= bridges[ii][1]) || (selected[0] <= bridges[ii][0] && selected[1] >= bridges[ii][1]))){
            valid.push_back(bridges[ii]);
        }
    }
    return valid;
}
int recurse(const vector<Bridge> &bridges){
    if(bridges.size()==0){
        return 0;
    } else if(bridges.size()==1){
        return bridges[0][2];
    }
    int max = 0;
    for(auto i : bridges){

        auto temp = validBridges(i,bridges);
        int hold = recurse(temp);
        hold += i[2];
        if(max < hold){
            max = hold;
        }
    }

    return max;
}

int build(int w, int e, const vector<Bridge> &bridges){
    auto allBridges = bridges;
    sort(allBridges.begin(),allBridges.end(),compare);
    removeDups(allBridges);
    return recurse(allBridges);

};
