//MEMOIZATION

    int solve(vector<int>& nums, int curr,int prevInd,vector<vector<int>>& dp){
        if(curr < 0){
            return 0;
        }

        if(dp[curr][prevInd] != -1){
            return dp[curr][prevInd];
        }

        int take = 0;
        int notTake = solve(nums,curr-1,prevInd,dp);

        if(prevInd == curr){
            take = 1 + solve(nums,curr-1,curr,dp);
            notTake = solve(nums,curr-1,curr-1,dp);
        }else if(nums[curr] < nums[prevInd]){
            take = 1 + solve(nums,curr-1,curr,dp);
        }

        return dp[curr][prevInd] = max(notTake,take);
        
    }

//TABULATION

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // int maxElement = *max_element(nums.begin(),nums.end());

        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int curr = 1;curr<=n;curr++){
            for(int prev =1;prev<=n;prev++){
                int take = 0;
                int notTake = dp[curr-1][prev];

                if(prev == curr){
                    take = 1 + dp[curr-1][curr];
                    notTake = dp[curr-1][curr-1];
                }
                else if(nums[curr-1] < nums[prev-1]){
                    take = 1 + dp[curr-1][curr];
                }

                dp[curr][prev] = max(notTake,take);
            }
        }
        return dp[n][n];
    }

//SPACE OPTIMISATION

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // int maxElement = *max_element(nums.begin(),nums.end());

        vector<int> current(n+1,0),previous(n+1,0);

        for(int curr = 1;curr<=n;curr++){
            for(int prev =1;prev<=n;prev++){
                int take = 0;
                int notTake = previous[prev];

                if(prev == curr){
                    take = 1 + previous[curr];
                    notTake = previous[curr-1];
                }
                else if(nums[curr-1] < nums[prev-1]){
                    take = 1 + previous[curr];
                }

                current[prev] = max(notTake,take);
            }
            previous = current;
        }
        return previous[n];
    }
