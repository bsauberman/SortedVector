//
// Created by Ben Sauberman on 11/28/18.
//

#include "SortedVector.h"
#include <vector>
using namespace std;

template<typename N>
SortedVector<N>::SortedVector() {

}


template<typename N>
//adds the object passed in to the end of the vector
int SortedVector<N>::push_tail(N t){
    group.push_back(t);
    return 1;
}

template<typename N>
//puts t at the end of the vector and then re-sorts the vector
//opCount is returned. opCount = the number of operations it took to add the element and then re-sort
int SortedVector<N>::insertSorted(N t) {
    int opCount = 0;
    if(group.size() == 0){
        group.push_back(t);
        opCount++;
    }else{
        group.push_back(t);
        for(int i = 0; i < group.size(); i++){
            if(group.at(group.size()-1) < group.at(i)){
                N temp = group.at(group.size()-1);
                opCount++;
                group.at(group.size()-1) = group.at(i);
                opCount++;
                group.at(i) = temp;
                opCount++;
            }
        }
    }

    return opCount;
}


template<typename N>
//returns a string of a printed version of the vector, using each object in the vector's print function
string SortedVector<N>::print() {
    string list = "";

    for(int i = 0; i < group.size(); i++){
        list+= group.at(i).print() + "\n";
    }

    return list;
}

template<typename N>
//uses a binary search to find the object in the vector by comparing it to the middle value
//and comparing the values. if object being searched for is less than that mid,
// it ignores everything bigger than that  value and re-searches with mid now as the midpoint
// between the beginning and the old mid (now the end)
//process repeats until value is found
//returns opCount which increases everytime it compares a value or cuts the search in half
int SortedVector<N>::search(N &t) {
    int opCount = 0;

    bool found = false;
    int max = group.size()-1;
    int min = 0;
    int mid = (max+min)/2;

    while(!found){
        if(group.at(mid) == t){
            opCount++;
            return opCount;
        }else if(group.at(mid) < t){
            min = mid+1;
            mid = (min+max)/2;
            opCount++;
        }else if(group.at(mid) > t) {
            max = mid;
            mid = (min + max) / 2;
            opCount++;
        }else{
            return opCount;
        }
    }
    return opCount;
}