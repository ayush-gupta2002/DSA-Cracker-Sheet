// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long int mid,int cooks,int pratas,vector<int>& ranks){
    int prataCount = 0;
    for(int i=0;i<ranks.size();i++){
        long long int currentTime = 0;
        int currentFactor = 1;
        while(true){
            currentTime += (currentFactor * ranks[i]);
            if(currentTime > mid){
                break;
            }
            currentFactor++;
            prataCount++;
        }
        if(prataCount >= pratas){
            return true;
            
        }
    }
    return false;
}

long long int rotiPrata(int pratas,int cooks,vector<int>& ranks){
    long long int lo = 0;
    int lowestRank = *max_element(ranks.begin(),ranks.end());
    long long int hi = 1e8;
    // for(int i=1;i<=pratas;i++){
    //     hi += (4*i);
    // }
    long long int mid = lo + (hi-lo)/2;
    long long int ans = -1;
    
    while(lo<=hi){
        if(isPossible(mid,cooks,pratas,ranks)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
        mid = lo + (hi-lo)/2;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int pratas,cooks;
        cin>>pratas>>cooks;
        vector<int> ranks(cooks);
        for(int i=0;i<cooks;i++){
            cin>>ranks[i];
        }
        cout<<rotiPrata(pratas,cooks,ranks);
        cout<<endl;
    }

    return 0;
}
