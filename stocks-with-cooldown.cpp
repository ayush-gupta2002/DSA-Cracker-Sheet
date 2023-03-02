//MEMOIZATION

#include <bits/stdc++.h> 
using namespace std;
    int solve(vector<int>& prices,int curr,bool isHolding,bool canBuy,vector<vector<vector<int>>>& dp){
        
        if(curr == prices.size()){
            return 0;
        }
        
        if(dp[curr][isHolding][canBuy] != -1){
            return dp[curr][isHolding][canBuy];
        }
        
        int ans = 0;
        if(!isHolding && canBuy){
            int ans1 = -prices[curr] + solve(prices,curr+1,true,false,dp);
            int ans2 = solve(prices,curr+1,false,true,dp);
            ans = max(ans1,ans2);
        }
        else if(isHolding && !canBuy){
            int ans1 = prices[curr] + solve(prices,curr+1,false,false,dp);
            int ans2 = solve(prices,curr+1,true,false,dp);
            ans = max(ans1,ans2);
        }
        else if(!isHolding && !canBuy){
            ans = solve(prices,curr+1,false,true,dp);
        }
        
        return dp[curr][isHolding][canBuy] = ans;
    }
int stockProfit(vector<int> &prices){
    int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (2,-1)));
        return solve(prices,0,false,true,dp);
}

//TABULATION

int stockProfit(vector<int> &prices){
    int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (2,0)));

        for(int curr=n-1;curr>=0;curr--){
            for(int isHolding=0;isHolding<=1;isHolding++){
                for(int canBuy=0;canBuy<=1;canBuy++){
                    // int ans = 0;
                    if(!isHolding && canBuy){
                        int ans1 = -prices[curr] + dp[curr+1][1][0];
                        int ans2 = dp[curr+1][0][1];
                        // cout<<ans1<<ans2<<endl;
                        dp[curr][isHolding][canBuy] = max(ans1,ans2);
                        // cout<<ans<<" ";
                    }
                    else if(isHolding && !canBuy){
                        int ans1 = prices[curr] + dp[curr+1][0][0];
                        int ans2 = dp[curr+1][1][0];
                        dp[curr][isHolding][canBuy] = max(ans1,ans2);

                    }
                    else if(!isHolding && !canBuy){
                        dp[curr][isHolding][canBuy] = dp[curr+1][0][1];
                       
                    }
                    // cout<<curr<<" "<<isHolding<<" "<<canBuy<<" "<<dp[curr][isHolding][canBuy]<<endl;
                    // cout<<ans<<" ";

                }
            }
        }

        return dp[0][0][1];
}

//SPACE OPTIMISATION

#include <bits/stdc++.h> 
int stockProfit(vector<int> &prices){
    int n = prices.size();
        vector<vector<int>> current(2,vector<int>(2,0)), next(2, vector<int>(2,0))

        for(int curr=n-1;curr>=0;curr--){
            for(int isHolding=0;isHolding<=1;isHolding++){
                for(int canBuy=0;canBuy<=1;canBuy++){
                    // int ans = 0;
                    if(!isHolding && canBuy){
                        int ans1 = -prices[curr] + next[1][0];
                        int ans2 = next[0][1];
                        // cout<<ans1<<ans2<<endl;
                        current[isHolding][canBuy] = max(ans1,ans2);
                        // cout<<ans<<" ";
                    }
                    else if(isHolding && !canBuy){
                        int ans1 = prices[curr] + next[0][0];
                        int ans2 = next[1][0];
                        current[isHolding][canBuy] = max(ans1,ans2);

                    }
                    else if(!isHolding && !canBuy){
                       current[isHolding][canBuy] = next[0][1];
                       
                    }
                    // cout<<curr<<" "<<isHolding<<" "<<canBuy<<" "<<dp[curr][isHolding][canBuy]<<endl;
                    // cout<<ans<<" ";

                }
                next = current;
            }
        }

        return next[0][1];
}
