#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long int>& trees,long long int mid,long long int M,long long int N){
    long long int currentSum = 0;
    for(int i=0;i<N;i++){
        if(trees[i]>mid){
            currentSum += (trees[i]-mid);
            if(currentSum>=M){
                return true;
            }
        }
    }
    return false;
}

long long int maxSawblade(vector<long long int>& trees,long long int N,long long int M){
    sort(trees.begin(),trees.end());
    long long int lo = 0;
    long long int hi = trees[N-1];
    long long int mid = lo + (hi-lo)/2;
    long long int ans = -1;
    
    while(lo<=hi){
        if(isPossible(trees,mid,M,N)){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
        mid = lo + (hi-lo)/2;
    }
    return ans;
}

int main(){
    long long int N,M;
    cin>>N>>M;
    vector<long long int> trees(N);
    for(int i=0;i<N;i++){
        cin>>trees[i];
    }
    long long int ans = maxSawblade(trees,N,M);
    cout<<ans;
    return 0;
}
