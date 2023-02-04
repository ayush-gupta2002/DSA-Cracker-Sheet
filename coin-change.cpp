//MEMOIZATION

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

//TABULATION

	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M, vector<int> (V+1,0));
	    
	    for(int curri=0;curri<M;curri++){
	        for(int target=0;target<=V;target++){
	            if(target == 0){
	                dp[curri][0] = 0;
	            }
	            else if(curri == 0){
	                if(target%coins[0] == 0){
	                    dp[0][target] = target/coins[0];
	                }
	                else{
	                    dp[0][target] = 1e9;
	                }
	            }
	            else{
	                int left = INT_MAX;
	                if(target >= coins[curri]){
	                    left = 1 + dp[curri][target-coins[curri]];
	                }
	                int right = dp[curri-1][target];
	                dp[curri][target] = min(left,right);
	            }
	        }
	    }
	    if(dp[M-1][V] >= 1e9){
	        return -1;
	    }
	    return dp[M-1][V];
	} 
