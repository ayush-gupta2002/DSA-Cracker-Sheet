// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void printSubsequence(string currentString, int index, string ogString){
    if(index==ogString.length()){
        for(auto i:currentString){
            cout<<i;
        }cout<<endl;
        return;
    }
    currentString.push_back(ogString[index]);
    printSubsequence(currentString,index+1,ogString);
    currentString.pop_back();
    printSubsequence(currentString,index+1,ogString);
    }

int main() {
    // Write C++ code here
    printSubsequence("",0,"abba");

    return 0;
}
