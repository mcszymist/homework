// contigsum.hpp
// Glenn G. Chappell created base Merge sort
// Modified by Tyler J Roberts to create an effencient GCS algorithm
// 10 Oct 2018
// Merge Sort Type GCS calculator

#ifndef CONTIGSUM_H_INCLUDED
#define CONTIGSUM_H_INCLUDED
#include <algorithm>
using std::max;
#include <iterator>
using std::distance;
using std::advance;

struct GCS{
    int gcs = 0;        //The GCS of the sequence.
    int sumFirst = 0;   //THe greatest possible sum of first
    int sumLast = 0;    //The greatest possible sum of last
    int sumAll = 0;     //The sum of the entire sequence
};

const GCS findGCSMerge(const GCS &front,const GCS &back){
    GCS hold{};
    hold.gcs =      max(max(front.gcs,back.gcs),front.sumLast+back.sumFirst);
    hold.sumFirst = max(front.sumFirst,front.sumAll+back.sumFirst);
    hold.sumLast =  max(front.sumLast+back.sumAll,back.sumLast);
    hold.sumAll =   front.sumAll + back.sumAll;
    return hold;
}
template<typename RAIter>
const GCS recursiveGCS(RAIter first, RAIter last){
    auto size = distance(first, last);
    if(size == 1){
        GCS ret{};
        ret.gcs = *first;
        ret.sumFirst = *first;
        ret.sumLast = *first;
        ret.sumAll = *first;
        return ret;
    }
    RAIter middle = first;
    advance(middle, size/2); 

    auto front = recursiveGCS(first, middle);
    auto back = recursiveGCS(middle, last);
   
    return findGCSMerge(front,back);
}

template<typename RAIter>
int contigSum(RAIter first, RAIter last){
    auto size = distance(first, last);
    if(size == 0){
        return 0;
    }
    if(size == 1){
        if(*first < 0)
            return 0;
        return *first;
    }
    if(recursiveGCS(first,last).gcs < 0)
        return 0;
    return recursiveGCS(first,last).gcs;
}

#endif