#include "SortedVector.h"
#include "SortedVector.cpp"
#include "Team.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

int strtoi(string s) {
    return atoi(s.c_str());
}

double strtod(string s) {
    return atof(s.c_str());
}


const int SIZE_OF_FILE = 214;
const int NUM_OF_TIMES = 50;

int main() {
    srand(time(0));

    vector<int> countOfOpsInsert;
    vector<int> countOfOpsSearch;
    vector<int> countOfNum;

    for(int j = 1; j < NUM_OF_TIMES+1; j++) {
        //open file for rankings
        ifstream file("../soccerrankings.csv");
        //ignore header characters
        file.ignore(28);

        //initialize the vector of type team
        SortedVector<Team> vectorOfTeams;
        cout << "Reading ../soccerrankings.csv..." << endl;

        vector<Team> genList;

        //read in data from file
        while (!file.eof() && genList.size() <= (SIZE_OF_FILE/NUM_OF_TIMES)*j) {
            int rank;
            string name;
            string confed;
            double off;
            double def;
            double spi;
            string temp;

            getline(file, temp, ',');
            rank = strtoi(temp);

            getline(file, name, ',');

            getline(file, confed, ',');

            getline(file, temp, ',');
            off = strtod(temp);

            getline(file, temp, ',');
            def = strtod(temp);

            getline(file, temp, '\n');
            spi = strtod(temp);

            genList.push_back(Team(rank, name, confed, off, def, spi));
        }

        //shuffle vector of Teams
        for (int i = 0; i < (rand() % (100000)); i++) {
            int a = rand() % genList.size();
            int b = rand() % genList.size();
            Team temp = genList.at(a);
            genList.at(a) = genList.at(b);
            genList.at(b) = temp;
        }

        int opCountInsert = 0;
        int opCountSearch = 0;
        //add Teams to vector
        for (int i = 0; i < genList.size(); i++) {
            opCountInsert+= vectorOfTeams.insertSorted(genList.at(i));
        }

        //search vector
        for (int i = 0; i < genList.size(); i++) {
            opCountSearch+= vectorOfTeams.search(genList.at(i));
        }

        cout << "Writing data in sorted vector into output.txt" << endl;

        //create output stream with file
        ofstream stackOutput("../output.txt");

        //output to file
        stackOutput << vectorOfTeams.print();

        //close data and read-in files
        file.close();
        stackOutput.close();
        countOfOpsSearch.push_back(opCountSearch);
        countOfOpsInsert.push_back(opCountInsert);
        countOfNum.push_back(genList.size());
    }

    ofstream stats("../stat.txt");

    for(int i = 0; i < countOfOpsSearch.size(); i++){
        stats << countOfOpsInsert.at(i) << ',' << countOfOpsSearch.at(i) << ',' << countOfNum.at(i) << "\n";
    }

    stats.close();
}