//MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& num, int tar, int curri,vector<vector<int>>& dp){
    if(tar == 0){
        return 1;
    }
    else if(curri == 0){
        if(num[curri] == tar){
            return 1;
        }
        return 0;
    }
    else if(tar < 0){
        return 0;
    }
    if(dp[curri][tar] != -1){
        return dp[curri][tar];
    }

    int left = solve(num,tar - num[curri],curri-1,dp);
    int right = solve(num,tar,curri-1,dp);

    return dp[curri][tar] = left + right;

}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1,-1));
    return solve(num,tar,n-1,dp);
}

//TABULATION

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    if(num[0] <= tar){
        dp[0][num[0]] = 1;
    }

    for(int i=1;i<n;i++){
        for(int s1=1;s1<=tar;s1++){
            int left = 0;
            if(num[i] <= s1){
                left = dp[i-1][s1-num[i]];
            }
            int right = dp[i-1][s1];
            dp[i][s1] = left + right;
        }
    }
    return dp[n-1][tar];
}
