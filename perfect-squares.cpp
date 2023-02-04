class Solution {
public:

    int solve(int n,int curri,vector<int>& dp){
        if(n==0){
            return 0;
        }
        else if(n<0){
            return 1e9;
        }
        else if(curri*curri > n){
            return 1e9;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int left = solve(n,curri+1,dp);
        int right = 1 + solve(n-(curri*curri),curri,dp);
        return dp[n] = min(left,right);
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,1,dp);
    }
};
