/**
 * @file day03.cpp
 * @author Miguel Ángel Moreno Castro
 * @date Dec 3, 2022
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> Read (const string & file){
    ifstream fi(file);
    vector<string> aux;
    string temp;

    if (fi.is_open()){
        while (getline(fi, temp))
            aux.push_back(temp);
        fi.close();
    }

    return aux;
}

vector<char> ReadRuckSack (const vector<string> & rucksacks){
    vector<char> aux;
    string temp;
    char item;
    bool found = true;

    for (int i = 0; i < rucksacks.size(); i++){
        temp = rucksacks.at(i);
        for (int j = 0; j < temp.size()/2 && found; j++){
            item = temp.at(j);
            for (int k = temp.size()/2; k < temp.size() && found; k++){
                if (item == temp.at(k))
                    found = false;
            }
        }
        aux.push_back(item);
        found = true;
    }

    return aux;
}

vector<char> ReadBadge (const vector<string> & rucksacks){
    vector<char> aux;
    string temp01, temp02, temp03;
    char item;
    bool found = true;

    for (int i = 0; i < rucksacks.size(); i += 3) {
        temp01 = rucksacks.at(i);
        temp02 = rucksacks.at(i + 1);
        temp03 = rucksacks.at(i + 2);
        for (int j = 0; j < temp01.size() && found; j++){
            item = temp01.at(j);
            for (int k = 0; k < temp02.size() && found; k++){
                if (item == temp02.at(k)){
                    for (int l = 0; l < temp03.size() && found; l++){
                        if (item == temp03.at(l))
                            found = false;
                    }
                }
            }
        }
        aux.push_back(item);
        found = true;
    }
    return aux;
}

int Priorities (const vector<char> & items){
    int sum = 0;
    int lowercasediff = 'a' - 1;
    int uppercasediff = 'A' - 27;

    for (int i = 0; i < items.size(); i++){
        if (items.at(i) - lowercasediff > 0)
            sum += (items.at(i) - lowercasediff);
        else
            sum += (items.at(i) - uppercasediff);
    }

    return sum;
}

int Puzzle1 (const vector<char> & doubled){
    return Priorities(doubled);
}

int Puzzle2 (const vector<char> & common){
    return Priorities(common);
}

int main (int argc, char * argv[]){

    if (argc != 2)
        exit(1);

    vector<string> rucksacks = Read(argv[1]);

    for (int i = 0; i < rucksacks.size(); i++)
        cout << rucksacks.at(i) << endl;

    cout << "\nThe sum of the priorities of the doubled items is " << Puzzle1(ReadRuckSack(rucksacks));
    cout << "\nThe sum of the priorities of the badges is " << Puzzle2(ReadBadge(rucksacks));

    return 0;
}