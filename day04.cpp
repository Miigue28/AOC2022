/**
 * @file day04.cpp
 * @author Miguel Ángel Moreno Castro
 * @date Nov 4, 2022
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cstring>

using namespace std;

vector<pair<int, int>> Read (const string & file){
    ifstream fi(file);
    string temp;
    vector<pair<int, int>> aux;
    pair<int, int> elf01;
    pair<int, int> elf02;

    if (fi.is_open()){
        while (getline(fi, temp)){
            elf01.first = stoi(strtok(temp.data(), "-"));
            elf01.second = stoi(strtok(NULL, ","));
            elf02.first = stoi(strtok(NULL, "-"));
            elf02.second = stoi(strtok(NULL, " "));
            aux.push_back(elf01);
            aux.push_back(elf02);
        }
        fi.close();
    }
    return aux;
}

int Puzzle1 (const vector<pair<int, int>> & overlaps){
    int total = 0;

    for (int i = 0; i < overlaps.size(); i += 2){
        int min1 = overlaps[i].first;
        int max1 = overlaps[i].second;
        int min2 = overlaps[i+1].first;
        int max2 = overlaps[i+1].second;

        if ((min1 <= min2 &&  max1 >= max2) || (min1 >= min2 && max1 <= max2))
            total++;
    }
    return total;
}

int Puzzle2 (const vector<pair<int, int>> & overlaps){
    int total = 0;

    for (int i = 0; i < overlaps.size(); i += 2){
        int min1 = overlaps[i].first;
        int max1 = overlaps[i].second;
        int min2 = overlaps[i+1].first;
        int max2 = overlaps[i+1].second;

        if ((min1 <= max2 && max1 >= min2)  ||  (min1 >= max2 && max1 <= min2))
            total++;
    }
    return total;
}

int main (int argc, char * argv[]){

    if (argc != 2)
        exit(1);

    vector<pair<int, int>> overlaps = Read(argv[1]);

    cout << "\nThe number of assignment pairs that one range fully contains the other is " << Puzzle1(overlaps);
    cout << "\nThe number of assigment pairs that the ranges overlap is " << Puzzle2(overlaps);

    return 0;
}