#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <regex>
#include <sstream>
using namespace std;

map<string, int> cubes = {
    {"red", 12},
    {"green", 13},
    {"blue", 14}
};

void matcher(string str, regex re, list<string>& results) {
    sregex_iterator match(str.begin(), str.end(), re);
    sregex_iterator lastMatch;

    while (match != lastMatch) {
        smatch currentMatch = *match;
        results.push_back(currentMatch.str());
        match++;
    }
}

int main(){
    ifstream file("./day2input.txt");
    string tp;
    regex re("([0-9]+ [a-z]+)");

    int counter = 0;
    int index = 1;
    while(getline(file, tp)) {
        list<string> results; 
        matcher(tp, re, results);

        int pos;
        int number;
        string color;
        int comparator;
        int successes = 0;
        for (auto x : results) {
            pos = x.find(" ");
            number = stoi(x.substr(0, pos));
            color = x.substr(pos+1, x.back());
            comparator = cubes.at(color);

            if (number > comparator) {
                break;
            } else {
                successes++;
            }
        }

        if (successes == results.size()) {
            counter += index;
        } 

        index++;
    }

    file.close();
    return 0;
}