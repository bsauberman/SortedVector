//
// Created by lange on 11/19/2018.
//

#ifndef PROJECT_7_PART_1_STACK_LANGEFELD_ROBERT_SAUBERMAN_BEN_2_TEAM_H
#define PROJECT_7_PART_1_STACK_LANGEFELD_ROBERT_SAUBERMAN_BEN_2_TEAM_H

#include <string>
#include <iostream>
using namespace std;

class Team{
private:
    int rank;
    string name;
    string confed;
    double off;
    double def;
    double spi;
public:
    Team();
    Team(int r, string n, string c, double o, double d, double s);
    string print();
    bool operator<(Team &t);
    bool operator>(Team &t);
    bool operator==(Team &t);
    friend ostream & operator <<(ostream &os, Team &r);
};


#endif //PROJECT_7_PART_1_STACK_LANGEFELD_ROBERT_SAUBERMAN_BEN_2_TEAM_H
