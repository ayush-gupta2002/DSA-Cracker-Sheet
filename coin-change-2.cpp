//MEMOIZATION

class Solution {
public:

    int solve(int amount,vector<int>& coins,int curri,vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(curri == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        else if(curri<0){
            return 0;
        }

        if(dp[curri][amount] != -1){
            return dp[curri][amount];
        }

        int left = 0;
        if(amount >= coins[curri]){
            left = solve(amount-coins[curri],coins,curri,dp);
        }
        int right = solve(amount,coins,curri-1,dp);
        return dp[curri][amount] = left+right;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        return solve(amount,coins,n-1,dp);
    }
};

//TABULATION

class Solution {
public:

    int solve(int amount,vector<int>& coins,int curri,vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(curri == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        else if(curri<0){
            return 0;
        }

        if(dp[curri][amount] != -1){
            return dp[curri][amount];
        }

        int left = 0;
        if(amount >= coins[curri]){
            left = solve(amount-coins[curri],coins,curri,dp);
        }
        int right = solve(amount,coins,curri-1,dp);
        return dp[curri][amount] = left+right;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        for(int curri=0;curri<n;curri++){
            for(int amt=0;amt<=amount;amt++){
                if(amt==0){
                    dp[curri][amt] = 1;
                }
                else if(curri==0){
                    if(amt % coins[0] == 0){
                        dp[curri][amt] = 1;
                    }
                    else{
                        dp[curri][amt] = 0;
                    }
                }
                else{
                    int left = 0;
                    if(amt >= coins[curri]){
                        left = dp[curri][amt-coins[curri]];
                    }
                    int right = dp[curri-1][amt];

                    dp[curri][amt] = left + right;
                }
            }
        }
        return dp[n-1][amount];
    }
};

//SPACE OPTIMISED TABULATION

class Solution {
public:

    int solve(int amount,vector<int>& coins,int curri,vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(curri == 0){
            if(amount % coins[0] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        else if(curri<0){
            return 0;
        }

        if(dp[curri][amount] != -1){
            return dp[curri][amount];
        }

        int left = 0;
        if(amount >= coins[curri]){
            left = solve(amount-coins[curri],coins,curri,dp);
        }
        int right = solve(amount,coins,curri-1,dp);
        return dp[curri][amount] = left+right;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int curri=0;curri<n;curri++){
            for(int amt=0;amt<=amount;amt++){
                if(amt==0){
                    curr[amt] = 1;
                }
                else if(curri==0){
                    if(amt % coins[0] == 0){
                        curr[amt] = 1;
                    }
                    else{
                        curr[amt] = 0;
                    }
                }
                else{
                    int left = 0;
                    if(amt >= coins[curri]){
                        left = curr[amt-coins[curri]];
                    }
                    int right = prev[amt];

                    curr[amt] = left + right;
                }
            }
            prev = curr;
        }
        return prev[amount];
    }
};
