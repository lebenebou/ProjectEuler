
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

unsigned short value(const string& name){

    unsigned short answer = 0;
    for(const char& c : name){

        answer += int(c) - 64;
    }
    return answer;
}

int main(){

    ifstream f("./Files/p22_names.txt");

    string fcontent;
    while (getline (f, fcontent)) {}
    f.close();

    vector<string> names(5163);

    unsigned short i = 0;
    short filled = 0;
    
    string name = "";
    while(filled < 5162){

        if(fcontent[i]=='/'){

            names[filled++] = name;
            name = "";

        } else {
            name += fcontent[i];
        }

        i++;
    }

    names[5162] = "ALONSO";
    sort(names.begin(), names.end());

    unsigned int answer = 0;

    for(short i=0; i<names.size(); i++){

        answer += (i+1)*(value(names[i]));
    }

    cout << answer << endl;

    return 0;
}