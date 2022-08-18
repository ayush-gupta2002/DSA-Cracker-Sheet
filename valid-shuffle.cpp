// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValidShuffle(string str1,string str2){
    if(str1.length()>str2.length()){
        return false;
    }
    unordered_map<char,int> frequency_map;
    for(char i:str1){
        frequency_map[i]++;
    }
    int window_size = str1.length();
    int n = str2.length();
    int i = 0;
    int j = 0;
    while(j<n){
        cout<<"current window "<<str2.substr(i,(j-i+1))<<endl;
        cout<<"current hash map ";
        if(frequency_map.find(str2[j]) != frequency_map.end()){
            frequency_map[str2[j]]--;
        }
        if(frequency_map[str2[j]]==0){
            frequency_map.erase(str2[j]);
        }
        for(auto i:frequency_map){
            cout<<i.first<<i.second<<" ";
        }cout<<endl;
        if((j-i+1)<window_size){
            j++;
        }
        else if((j-i+1)==window_size){
            if(frequency_map.size()==0){
                return true;
            }
            else{
                if(frequency_map.find(str2[i]) != frequency_map.end()){
                    frequency_map[str2[i]]++;
                }
                i++;
                j++;
            }
        }
    }
    return false;
    
}

int main() {
    // Write C++ code here
    cout<<isValidShuffle("onetwofour","hellofourtwooneworld”);

    return 0;
}
