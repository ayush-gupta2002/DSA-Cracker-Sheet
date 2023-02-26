//SPACE OPTIMISED APPROACH

#include <bits/stdc++.h> 
using namespace std;


int minInsertion(string &s)
{
        int n = s.size();
        vector<int> curr(n+1),prev(n+1);
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    curr[ind2] = 1 + prev[ind2-1];
                }
                else{
                    curr[ind2] =max(prev[ind2],curr[ind2-1]);
                }
            }
            prev = curr;
        }

        int LCS = curr[n];

        return n - LCS;
}
