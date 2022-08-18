// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<char> duplicates(string s){
    int n = s.length();
    unordered_map<char,int> hash_map;
    for(auto i:s){
        hash_map[i]++;
    }
    vector<char> duplicates;
    for(auto i:hash_map){
        if(i.second>=2){
            duplicates.push_back(i.first);
        }
    }
    return duplicates;
}

int main() {
    vector<char> duplicates_ = duplicates("test string");
    for(auto i:duplicates_){
        cout<<i;
    }

    return 0;
}
