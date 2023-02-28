//MEMOIZATION
class Solution {
public:

    int solve(vector<int>& prices,int curr,int n,bool canBuy,vector<vector<vector<int>>>& dp,int cap){
        if(cap<=0){
            return 0;
        }
        if(curr >= n){
            return 0;
        }

        if(dp[curr][canBuy][cap] != -1){
            return dp[curr][canBuy][cap];
        }

        if(canBuy){
            return dp[curr][canBuy][cap] = max(solve(prices,curr+1,n,false,dp,cap)-prices[curr], solve(prices,curr+1,n,true,dp,cap));
        }
        else{
            return dp[curr][canBuy][cap] = max(solve(prices,curr+1,n,true,dp,cap-1)+prices[curr], solve(prices,curr+1,n,false,dp,cap));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3,-1)));
        return solve(prices,0,n,true,dp,2);
    }
};

//TABULATION

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (3,0)));

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap=1;cap<=2;cap++){

                    if(canBuy){
                        dp[curr][canBuy][cap] = max(dp[curr+1][0][cap]-prices[curr], dp[curr+1][1][cap]);
                    }
                    else{
                        dp[curr][canBuy][cap] = max(dp[curr+1][1][cap-1] + prices[curr], dp[curr+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }

//TABULATION WITH SPACE OPTIMISATION
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (3,0)));
        vector<vector<int>> current(2,vector<int> (3,0)), next(2,vector<int> (3,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap=1;cap<=2;cap++){

                    if(canBuy){
                        current[canBuy][cap] = max(next[0][cap]-prices[curr], next[1][cap]);
                    }
                    else{
                        current[canBuy][cap] = max(next[1][cap-1] + prices[curr], next[0][cap]);
                    }
                }
                next = current;
            }
        }

        return current[1][2];
    }
