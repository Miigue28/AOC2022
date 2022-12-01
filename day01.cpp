/**
 * @file day01.cpp
 * @author Miguel Ángel Moreno Castro
 * @date Dec 1, 2022
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> Read(const string & file){
    ifstream fi(file);
    string temp;
    vector<int> elves;
    int sum = 0;

    if (fi.is_open()){
        while (!fi.eof()){
            getline(fi, temp, '\n');
            if (!temp.empty()){
                sum += stoi(temp);
            } else {
                elves.push_back(sum);
                sum = 0;
            }
        }
    }

    return elves;
}

int Puzzle1(vector<int> elves){
    int max = elves.at(0);

    for (int i = 1; i < elves.size(); i++){
        if (max < elves.at(i))
            max = elves.at(i);
    }

    return max;
}

int Puzzle2(vector<int> elves){
    int max1, max2, max3;

    max1 = Puzzle1(elves);
    max2 = elves.at(0) > elves.at(1) ? elves.at(0) : elves.at(1);
    max3 = max2 == elves.at(0) ? elves.at(1) : elves.at(0);

    for (int i = 2; i < elves.size(); i++){
        if (max2 < elves.at(i) && elves.at(i) < max1){
            max3 = max2;
            max2 = elves.at(i);
        }
    }

    return max1 + max2 + max3;
}

int main(int argc, char * argv[]){

    if (argc != 2)
        exit(1);

    vector<int> elves = Read(argv[1]);

    cout << "\nThe maximum amount of calories carried by an elf is " << Puzzle1(elves);

    cout << "\nThe total amount of calories carried by the top three elves is " << Puzzle2(elves);

    return 0;
}