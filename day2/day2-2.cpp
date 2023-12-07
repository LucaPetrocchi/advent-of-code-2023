#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <regex>
#include <sstream>
using namespace std;

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

    map<string, int> cubes = {
        {"red", 0},
        {"green", 0},
        {"blue", 0}
    };

    int power = 0;
    while(getline(file, tp)) {
        list<string> results; 
        matcher(tp, re, results);

        int subpower = 0;

        int pos;
        int number;
        string color;
        int comparator;
        for (auto x : results) {
            pos = x.find(" ");
            number = stoi(x.substr(0, pos));
            color = x.substr(pos+1, x.back());

            if (cubes.at(color) < number) {
                cubes.at(color) = number;
            }
        }

        subpower = cubes.at("red") * cubes.at("green") * cubes.at("blue");
        power += subpower;

        for (auto& [_, v] : cubes) v = 0;

    }

    file.close();
    return 0;
}