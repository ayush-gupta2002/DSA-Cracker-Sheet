class Solution {
public:
    int climbUtil(int current,int n,vector<int>& dp){
        if(current <= 1){
            dp[current] = 1;
            return 1;
        }

        if(dp[current] == -1){
            dp[current] = climbUtil(current-1,n,dp) + climbUtil(current-2,n,dp);
        }
        return dp[current];
    }

    int climbStairs(int n) {
        int prev = 1;
        int prevToPrev = 1;
        if(n == 1 || n==0){
            return 1;
        }
        int current = 0;

        for(int i=2;i<=n;i++){
            current = prev + prevToPrev;
            prevToPrev = prev;
            prev = current;
        }
        return current;

    }
};
