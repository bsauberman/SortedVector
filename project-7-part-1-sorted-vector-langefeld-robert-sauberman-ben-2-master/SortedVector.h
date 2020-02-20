#ifndef PROJECT_7_PART_1_SORTED_VECTOR_LANGEFELD_ROBERT_SAUBERMAN_BEN_2_SORTEDVECTOR_H
#define PROJECT_7_PART_1_SORTED_VECTOR_LANGEFELD_ROBERT_SAUBERMAN_BEN_2_SORTEDVECTOR_H
#include <iostream>
#include "SortedVector.h"
#include "Team.h"
#include <string>
#include <vector>
using namespace std;

template<typename N>
class SortedVector {
private:
    vector<N> group;
public:
    SortedVector();
    string print();
    int insertSorted(const N t);
    int push_tail(const N t);
    int search(N &t);
};


#endif //PROJECT_7_PART_1_SORTED_VECTOR_LANGEFELD_ROBERT_SAUBERMAN_BEN_2_SORTEDVECTOR_H
