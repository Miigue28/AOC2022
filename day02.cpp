/**
 * @file day02.cpp
 * @author Miguel Ángel Moreno Castro
 * @date Dec 2, 2022
 */

#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

vector<pair<char, char>> Read(const string & file){
    ifstream fi(file);
    pair<char, char> temp;
    vector<pair<char, char>> strategy;
    string aux;

    if (fi.is_open()){
        while (getline(fi, aux)){
            temp.first = aux.at(0);
            temp.second = aux.at(2);
            strategy.push_back(temp);
        }
    }

    fi.close();
    return strategy;
}

int ScorePerRound(const pair<char, char> & input){
    int score;

    switch (input.first) {
        case 'A':
            if (input.second == 'Y')
                score = 2 + 6;
            else
                score = input.second == 'X' ? 1 + 3 : 3;
            break;
        case 'B':
            if (input.second == 'Z')
                score = 3 + 6;
            else
                score = input.second == 'Y' ? 2 + 3 : 1;
            break;
        case 'C':
            if (input.second == 'X')
                score = 1 + 6;
            else
                score = input.second == 'Z' ? 3 + 3 : 2;
            break;
    }

    return score;
}

vector<pair<char, char>> Guidance (const vector<pair<char, char>> & strategy){
    vector<pair<char, char>> aux;
    pair<char, char> temp;

    for (int i = 0; i < strategy.size(); i++){
        temp.first = strategy.at(i).first;
        switch (strategy.at(i).second) {
            case 'X':
                if (temp.first == 'A')
                    temp.second = 'Z';
                else
                    temp.second = temp.first == 'B' ? 'X' : 'Y';
                break;
            case 'Y':
                if (temp.first == 'A')
                    temp.second = 'X';
                else
                    temp.second = temp.first == 'B' ? 'Y' : 'Z';
                break;
            case 'Z':
                if (temp.first == 'A')
                    temp.second = 'Y';
                else
                    temp.second = temp.first == 'B' ? 'Z' : 'X';
                break;
        }
        aux.push_back(temp);
    }
    return aux;
}

int Puzzle1(const vector<pair<char, char>> & strategy){
    int total = 0;

    for (int i = 0; i < strategy.size(); i++)
        total += ScorePerRound(strategy.at(i));

    return total;
}

int Puzzle2(const vector<pair<char, char>> & strat){
    int total = 0;

    vector<pair<char, char>> newstrategy = Guidance(strat);

    for (int i = 0; i < newstrategy.size(); i++)
        total += ScorePerRound(newstrategy.at(i));

    return total;
}

int main(int argc, char * argv[]){

    vector<pair<char, char>> strategy = Read(argv[1]);

    cout << "\nThe total score for the first puzzle would be " << Puzzle1(strategy);
    cout << "\nThe total score for the second puzzle would be " << Puzzle2(strategy);

    return 0;
}