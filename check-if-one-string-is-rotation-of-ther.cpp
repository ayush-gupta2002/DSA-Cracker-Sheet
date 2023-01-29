#include <bits/stdc++.h> 
using namespace std;

int isCyclicRotation(string &p, string &q) 
{
    string concat = p+p;

    int i=0;
    int j=p.size()-1;
    // cout<<concat<<endl;

    while(j<concat.size()-1){
        // cout<<concat.substr(i,p.size())<<endl;
        if(concat.substr(i,p.size()) == q){
            return 1;
        }
        i++;
        j++;
    }
    return 0;
}
