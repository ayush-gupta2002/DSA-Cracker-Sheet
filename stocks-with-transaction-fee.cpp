//MEMOIZATION

class Solution {
public:

    int solve(vector<int>& prices, int fee, int n,bool canBuy,int curr,vector<vector<int>>& dp){
        if(curr == n){
            return 0;
        }

        if(dp[curr][canBuy] != -1){
            return dp[curr][canBuy];
        }

        int ans = 0;
        if(canBuy){
            int ans1 = -prices[curr] - fee + solve(prices,fee,n,false,curr+1,dp);
            int ans2 = solve(prices,fee,n,true,curr+1,dp);
            ans = max(ans1,ans2);
        }
        else{
            int ans1 = prices[curr] + solve(prices,fee,n,true,curr+1,dp);
            int ans2 = solve(prices,fee,n,false,curr+1,dp);
            ans = max(ans1,ans2);
        }

        return dp[curr][canBuy] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(prices,fee,n,true,0,dp);
    }
};

//TABULATION

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                int ans = 0;
                if(canBuy){
                    int ans1 = -prices[curr] - fee + dp[curr+1][0];
                    int ans2 = dp[curr+1][1];
                    dp[curr][canBuy] = max(ans1,ans2);
                }
                else{
                    int ans1 = prices[curr] + dp[curr+1][1];
                    int ans2 = dp[curr+1][0];
                    dp[curr][canBuy] = max(ans1,ans2);
                }
            }
        }

        return dp[0][1];
    }

//SPACE OPTIMISATION

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> current(2,0),next(2,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                int ans = 0;
                if(canBuy){
                    int ans1 = -prices[curr] - fee + next[0];
                    int ans2 = next[1];
                    current[canBuy] = max(ans1,ans2);
                }
                else{
                    int ans1 = prices[curr] + next[1];
                    int ans2 = next[0];
                    current[canBuy] = max(ans1,ans2);
                }
            }
            next = current;
        }

        return next[1];
    }
