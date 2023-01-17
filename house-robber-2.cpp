class Solution {
public:

    int solve(vector<int>& nums,int current,vector<int>& dp){
        if(dp[current] != -1){
            return dp[current];
        }
        if(current == 0){
            dp[0] = nums[0];
            return dp[0];
        }
        if(current == 1){
            dp[current] = max(nums[0],nums[1]);
            return dp[current];
        }

        //picked 
        int left,right;
        if(dp[current-2] == -1){
            left = nums[current] + solve(nums,current-2,dp);
        }
        else{
            left = nums[current] + dp[current-2];
        }

        //not picked
        if(dp[current-1] == -1){
            right = solve(nums,current-1,dp);
        }
        else{
            right = dp[current-1];
        }

        dp[current] = max(left,right);

        return max(left,right);


    }

    int rob(vector<int>& nums) {
        int N = nums.size();

        if(N == 1){
            return nums[0];
        }

        vector<int> nums2(N);
        for(int i=1;i<N;i++){
            nums2[i] = nums[i];
        }

        vector<int> dp(N,-1);
        vector<int> dp2(N,-1);
        return max(solve(nums,N-2,dp),solve(nums2,N-1,dp2));
    }
};
