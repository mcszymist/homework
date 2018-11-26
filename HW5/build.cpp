// build.cpp
// City to City Max Toll
// By Tyler J Roberts
// For CS411 HW5

#include "build.hpp"
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

//compare to sort bridges with west then sort same west bridges by east
const bool compare(const Bridge &a,const Bridge &b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

// remove duplicate bridges and replace with the better value
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
// pushing the position into the bridges for its location in the data vector
void engageDataLoc(vector<Bridge> &bridges){
    for(size_t i = 0; i < bridges.size();i++){
        bridges[i].push_back(i);
    }
}

// returns the valid bridges for the selected bridge out of the list.
vector<Bridge> validBridges(const Bridge &selected,const vector<Bridge> &bridges){
    vector<Bridge> valid{};
    for(size_t ii = 0;ii< bridges.size();ii++){
        if(!((selected[0] >= bridges[ii][0] && selected[1] <= bridges[ii][1]) || (selected[0] <= bridges[ii][0] && selected[1] >= bridges[ii][1]) || (selected[0] >= bridges[ii][0] && selected[1] >= bridges[ii][1]))){
            valid.push_back(bridges[ii]);
        }
    }
    return valid;
}

// recursive function to find the maximum tool
int recurse(const vector<Bridge> &bridges,vector<int> &data){
    if(bridges.empty()){
        return 0;
    } else if(bridges.size()==1){
        return bridges[0][2];
    }
    int max = 0;
    int hold = 0;
    for(auto &i : bridges){
        if(data[i[3]] != -1){
            hold = data[i[3]];
        } else {
            auto temp = validBridges(i, bridges);
            hold = recurse(temp,data);
            hold += i[2];
            data[i[3]] = hold;
        }
        if(max < hold){
            max = hold;
        }
    }

    return max;
}

//setup to recurse
int build(int w, int e, const vector<Bridge> &bridges){
    auto allBridges = bridges;

    sort(allBridges.begin(),allBridges.end(),compare);
    removeDups(allBridges);
    engageDataLoc(allBridges);
    vector<int> data(allBridges.size(),-1);
    return recurse(allBridges,data);
};
