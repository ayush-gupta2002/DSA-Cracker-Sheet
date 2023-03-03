//MEMOIZATION

class Solution {
public:

    int solve(int curr,int prev,vector<int>& satisfaction,vector<vector<int>>& dp){
        if(curr == satisfaction.size()){
            return 0;
        }

        if(dp[curr][prev] != -1){
            return dp[curr][prev];
        }

        int take = (satisfaction[curr]*(prev)) + solve(curr+1,prev+1,satisfaction,dp);
        int notTake = solve(curr+1,prev,satisfaction,dp);

        return dp[curr][prev] = max(take,notTake);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,1,satisfaction,dp);
    }
};

//TABULATION

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int> (n+2,0));
        sort(satisfaction.begin(),satisfaction.end());

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=n;prev>=1;prev--){
                int take = satisfaction[curr]*prev + dp[curr+1][prev+1];
                int notTake = dp[curr+1][prev];
                dp[curr][prev] = max(take,notTake);
            }
        }

        return dp[0][1];
    }

//SPACE OPTIMISATION

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<int> current(n+2,0), next(n+2,0); 
        sort(satisfaction.begin(),satisfaction.end());

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=n;prev>=1;prev--){
                int take = satisfaction[curr]*prev + next[prev+1];
                int notTake = next[prev];
                current[prev] = max(take,notTake);
            }
            next = current;
        }

        return current[1];
    }
