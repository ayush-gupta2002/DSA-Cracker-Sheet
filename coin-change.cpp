class Solution {
public:

    int solve(vector<int>& coins,int amount, int curri,vector<vector<int>>& dp){
        if(curri == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return 1e9;
        }
        else if(amount == 0){
            return 0;
        }
        if(dp[curri][amount] != -1){
            return dp[curri][amount];
        }

        //Take the coin and go
        int opt1 = 1e9;
        if(coins[curri] <= amount){
            opt1 = 1 + solve(coins,amount - coins[curri],curri,dp);
        }

        //Do not take the coin and go
        int opt2 = solve(coins,amount,curri - 1,dp);

        return dp[curri][amount] = min(opt1,opt2);


    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int res = solve(coins,amount,n-1,dp);
        if(res == 1e9){
            return -1;
        }
        return res;
    }
};
