//CHECKING ALL PROBABILITIES METHOD

class Solution {
public:

    int solve(vector<int>&nums, int target,int curri,vector<unordered_map<int,int>>& dp){
        if(curri == 0){
            if(target - nums[0] == 0 && target + nums[0] == 0){
                return 2;
            }
            if(target - nums[0] == 0){
                return 1;
            }
            else if(target + nums[0] == 0){
                return 1;
            }
            return 0;
        }

        else if(curri < 0){
            return 0;
        }

        if(dp[curri].find(target) != dp[curri].end()){
            return dp[curri][target];
        }

        int ans = 0;
        ans += solve(nums,target-nums[curri],curri-1,dp);
        ans += solve(nums,target+nums[curri],curri-1,dp);

        return dp[curri][target] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        return solve(nums,target,n-1,dp);
    }
};

//USING THE PROBLEM FINDING SUBSETS WITH A GIVEN DIFFERENCE

class Solution {
public:

    int solve(vector<int>&nums, int target,int curri,vector<unordered_map<int,int>>& dp){
        if(curri == 0){
            if(target - nums[0] == 0 && target + nums[0] == 0){
                return 2;
            }
            if(target - nums[0] == 0){
                return 1;
            }
            else if(target + nums[0] == 0){
                return 1;
            }
            return 0;
        }

        else if(curri < 0){
            return 0;
        }

        if(dp[curri].find(target) != dp[curri].end()){
            return dp[curri][target];
        }

        int ans = 0;
        ans += solve(nums,target-nums[curri],curri-1,dp);
        ans += solve(nums,target+nums[curri],curri-1,dp);

        return dp[curri][target] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        return solve(nums,target,n-1,dp);
    }
};
