//MEMOIZATION APPROACH

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int min(long long int A, long long int B){
    if(A > B){
        return B;
    }
    return A;
}

int solve(long long int N,long long int K,vector<long long int>& heights,long long int current,vector<long long int>& dp){
    if(current == 1){
        dp[current] = 0;
    }

    int minEnergy = INT_MAX;

    if(dp[current] == -1){
        for(int i=current-1;i>=1 && i>=(current-K);i--){
            minEnergy = min((solve(N,K,heights,i,dp) + abs(heights[current] - heights[i])), minEnergy);
        }
        dp[current] = minEnergy;
    }
    return dp[current];

}

int main(){
    long long int N,K;
    cin>>N>>K;
    vector<long long int> heights(N+1);
    vector<long long int> dp(N+1);
    for(long long int i=1;i<=N;i++){
        cin>>heights[i];
        dp[i] = -1;
    }
    cout<<solve(N,K,heights,N,dp)<<endl;
    return 0;
}

//TABULATION APPROACH

#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main(){
    long long int N,K;
    cin>>N>>K;
    vector<long long int> heights(N+1);
    vector<long long int> dp(N+1);
    for(long long int i=1;i<=N;i++){
        cin>>heights[i];
        dp[i] = -1;
    }
    dp[1] = 0;
    for(long long int i=2;i<=N;i++){
        long long int minEnergy = INT_MAX;
        for(long long int k=i-1;k>=1 && k>=(i-K);k--){
            minEnergy = min((dp[k] + abs(heights[i] - heights[k])), minEnergy);
        }
        dp[i] = minEnergy;
    }
    cout<<dp[N]<<endl;
    return 0;
}
