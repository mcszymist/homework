struct GCS{
    int gcs = 0;        //The GCS of the sequence.
    int sumFirst = 0;   //THe greatest possible sum of first
    int sumLast = 0;    //The greatest possible sum of last
    int sumAll = 0;     //The sum of the entire sequence
};

template<typename RAIter>
int contigSum(RAIter first, RAIter last){
    size_t size = distance(first, last);
    if(size == 0){
        return 0;
    }
    if(size == 1){
        if(first < 0)
            return 0;
        return first;
    }
    RAIter middle = first;
    advance(middle, size/2); 

    contigSum(first, middle);
    contigSum(middle, last);

    findGCS(first, middle, last);

}
template <typename RAIter>
GCS findGCS(RAIter first, RAIter middle, RAIter last){

}
