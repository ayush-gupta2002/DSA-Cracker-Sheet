//RECURSIVE APPROACH

class Solution {
public:

    int solve(vector<int>& nums,int current){
        if(current == 0){
            return nums[0];
        }
        if(current < 0){
            return 0;
        }

        //picked 
        int left = nums[current] + solve(nums,current-2);

        //not picked
        int right = solve(nums,current-1);

        return max(left,right);


    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        return solve(nums,nums.size()-1);
    }
};

//MEMOIZATION APPROACH

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

        vector<int> dp(N);
        for(int i=0;i<N;i++){
            dp[i] = -1;
        }
        return solve(nums,N-1,dp);
    }
};

//TABULATION APPROACH

class Solution {
public:

    int rob(vector<int>& nums) {
        int N = nums.size();

        if(N == 1){
            return nums[0];
        }

        vector<int> dp(N);
        for(int i=0;i<N;i++){
            dp[i] = -1;
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2;i<N;i++){
            int left = nums[i] + dp[i-2];
            int right = dp[i-1];
            dp[i] = max(left,right);
        }
        return dp[N-1];
    }
};

//TABULATION WITH SPACE OPTIMISATION

    int rob(vector<int>& nums) {
        int N = nums.size();

        if(N == 1){
            return nums[0];
        }

        int prevToPrev = nums[0];
        int prev = max(nums[0],nums[1]);

        for(int i=2;i<N;i++){
            int left = nums[i] + prevToPrev;
            int right = prev;
            int current = max(left,right);
            prevToPrev = prev;
            prev = current;
        }
        return prev;
    }
};
