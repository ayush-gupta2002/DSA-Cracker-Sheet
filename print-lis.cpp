   int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> res;
        int maxi = 1;
        int maxIndex = 0;
        vector<int> hash(n+1,-1);
        for(int i=0;i<n;i++){
            hash[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                    if(dp[prev] + 1 > dp[i]){
                        hash[i] = prev;
                    }
                    dp[i] = max(dp[prev] + 1,dp[i]);
                }
            }
            if(dp[i] > maxi){
                maxIndex = i;
                maxi = dp[i];
            }
        }

        while(hash[maxIndex] != maxIndex){
            res.push_back(nums[maxIndex]);
            maxIndex = hash[maxIndex];
        }

        for(int i:res){
            cout<<i<<" ";
        }
        return maxi;
    }
