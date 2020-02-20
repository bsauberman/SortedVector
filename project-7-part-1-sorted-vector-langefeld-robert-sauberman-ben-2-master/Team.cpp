//
// Created by lange on 11/19/2018.
//

#include "Team.h"
#include "Team.h"
#include <string>
using namespace std;

Team::Team(){

}

Team::Team(int r, string n, string c, double o, double d, double s){
    rank = r;
    name = n;
    confed = c;
    off = o;
    def = d;
    spi = s;
}
//compares the rank of the object being passed in's rank to THIS object's rank
//and returns true if THIS object is less than object being passed in
bool Team::operator<(Team &t){
    return (this->rank < t.rank);
}

//compares the rank of the object being passed in's rank to THIS object's rank
//and returns true if THIS object is less than object being passed in
bool Team::operator>(Team &t){
    return (this->rank > t.rank);
}

//compares the rank of the object being passed in's rank to this object's rank
//and returns true if THIS object is equal to object being passed in
bool Team::operator==(Team &t){
    return (this->rank == t.rank);
}

//overrides the << operator by now calling the print function (see below)
ostream& operator<<(ostream &os, Team &r){
    os << r.print();
    return os;
}

//prints the rank and name of this team
string Team::print(){
    return to_string(this->rank) + ": " + this->name;
}