class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,-1);
        for(int i=0;i<n;i++){
            hash[i] = i;
        }

        int maxi = INT_MIN;
        int maxIndex = 0;

        for(int curr=0;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(nums[prev] % nums[curr] == 0 || nums[curr] % nums[prev] == 0){
                    if(dp[prev] + 1 > dp[curr]){
                        dp[curr] = 1 + dp[prev];
                        hash[curr] = prev;
                    }
                }
            }
            if(maxi < dp[curr]){
                maxi = dp[curr];
                maxIndex = curr;
            }
        }

        vector<int> res;
        while(maxIndex != hash[maxIndex]){
            res.push_back(nums[maxIndex]);
            maxIndex = hash[maxIndex];
        }
        res.push_back(nums[maxIndex]);
        return res;
    }
};
