//MEMOIZATION
class Solution {
public:

    int solve(vector<int>& prices,int curr,int n,bool canBuy,vector<vector<int>>& dp){
        if(curr >= n){
            return 0;
        }

        if(dp[curr][canBuy] != -1){
            return dp[curr][canBuy];
        }

        if(canBuy){
            return dp[curr][canBuy] = max(solve(prices,curr+1,n,false,dp)-prices[curr], solve(prices,curr+1,n,true,dp));
        }
        else{
            return dp[curr][canBuy] = max(solve(prices,curr+1,n,true,dp)+prices[curr], solve(prices,curr+1,n,false,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(prices,0,n,true,dp);
    }
};

//TABULATION
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){

                if(canBuy == 1){
                    dp[curr][canBuy] = max((dp[curr+1][0]-prices[curr]),dp[curr+1][1]);
                }
                else{
                    dp[curr][canBuy] = max((dp[curr+1][1]+prices[curr]), dp[curr+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};

//TABULATION WITH SPACE OPTIMISATION
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> current(2,0),next(2,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){

                if(canBuy == 1){
                    current[canBuy] = max((next[0]-prices[curr]),next[1]);
                }
                else{
                    current[canBuy] = max((next[1]+prices[curr]), next[0]);
                }
            }
            next = current;
        }

        return current[1];
    }
