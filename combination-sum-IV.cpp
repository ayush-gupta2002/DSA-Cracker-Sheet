//MEMOIZATION    

int solve(vector<int>& nums,int target,int curri,vector<vector<int>>& dp){
        if(curri < 0){
            return 0;
        }
        else if(target == 0){
            return 1;
        }
        else if(target < 0){
            return 0;
        }

        if(dp[curri][target] != -1){
            return dp[curri][target];
        }

        int left = 0;
        if(nums[curri] <= target){
            left = solve(nums,target-nums[curri],nums.size()-1,dp);
        }
        int right = solve(nums,target,curri-1,dp);
        return dp[curri][target] = left + right;
    }
