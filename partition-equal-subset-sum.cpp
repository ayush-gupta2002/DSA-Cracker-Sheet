//MEMOIZATION
class Solution {
public:

    bool solve(vector<int>& nums,int totalSum,int currentSum,int curri,vector<vector<int>>& dp){
        if(currentSum == totalSum){
            return true;
        }
        else if(currentSum > totalSum){
            return false;
        }
        else if(curri >= nums.size()){
            return false;
        }

        if(dp[curri][currentSum] != -1){
            return dp[curri][currentSum];
        }

        bool left = solve(nums,totalSum-nums[curri],currentSum+nums[curri],curri+1,dp);
        bool right = solve(nums,totalSum,currentSum,curri+1,dp);

        return dp[curri][currentSum] = left || right;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int it:nums){
            totalSum += it;
        }
        vector<vector<int>> dp(n, vector<int> (totalSum+1,-1));

        return solve(nums,totalSum,0,0,dp);
    }
};

//TABULATION
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int it:nums){
            totalSum += it;
        }

        if(totalSum % 2 != 0){
            return false;
        }
        int k = totalSum/2;
        vector<vector<int>> dp(n,vector<int> (k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0] <= k){
            dp[0][nums[0]] = true;
        }

        for(int i=1;i<n;i++){
            for(int target = 1;target<=k;target++){
                bool left = false;
                if(target>=nums[i]){
                    left = dp[i-1][target-nums[i]];
                }
                bool right = dp[i-1][target];
                if(left || right){
                    dp[i][target] = true;
                }
                else{
                    dp[i][target] = false;
                }
            }
        }
        return dp[n-1][k];
    }
