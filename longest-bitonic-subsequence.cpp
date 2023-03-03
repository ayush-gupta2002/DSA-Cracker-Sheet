#include <bits/stdc++.h> 
    int lengthOfLIS(vector<int>& nums,vector<int>& dp) {
        int n = nums.size();


        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[prev] + 1,dp[i]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
    
    int lengthOfLISRev(vector<int>& nums,vector<int>& dp) {
        int n = nums.size();

        int maxi = 1;
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[prev] + 1,dp[i]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
int longestBitonicSequence(vector<int>& nums, int n) {
	    int maxi = 1;
	    vector<int> dp(n,1);
	    vector<int> dpRev(n,1);
	    lengthOfLIS(nums,dp);
	    lengthOfLISRev(nums,dpRev);
	    
	    for(int i=0;i<n;i++){
	        int ans = dp[i]+dpRev[i]-1;
	        maxi = max(maxi,ans);
	    }
	    
	    return maxi;
} 

