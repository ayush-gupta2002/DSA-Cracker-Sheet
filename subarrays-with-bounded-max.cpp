class Solution {
public:
    int count(vector<int>& nums, int bound){
        int cnt = 0;
        int ans = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] <= bound){
                cnt++;
                ans+=cnt;
            }
            else{
                cnt = 0;
            }
        }
        return ans;
        
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left-1);
    }
};
