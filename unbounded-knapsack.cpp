//MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;

int solve(int curri,int w,vector<int>& profit,vector<int>& weight,vector<vector<int>>& dp){
    if(curri==0){
        return profit[0]*(w/weight[0]);
    }

    else if(curri<0){
        return 0;
    }

    if(dp[curri][w] != -1){
        return dp[curri][w];
    }

    int left = 0;
    if(w >= weight[curri]){
        left = profit[curri] + solve(curri,w-weight[curri],profit,weight,dp);
    }
    int right = solve(curri-1,w,profit,weight,dp);
    return dp[curri][w] = max(left,right);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w+1,-1));
    return solve(n-1,w,profit,weight,dp);
}


//TABULATION

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int> (w+1,-1));

    for(int curri=0;curri<n;curri++){
        for(int wt=0;wt<=w;wt++){
            if(curri == 0){
                dp[0][wt] = profit[0]*(wt/weight[0]);
            }
            else{
                int left = 0;
                if(wt >= weight[curri]){
                    left = profit[curri] + dp[curri][wt - weight[curri]];
                }
                int right = dp[curri-1][wt];

                dp[curri][wt] = max(left,right);
            }
        }
    }
    return dp[n-1][w];
}
