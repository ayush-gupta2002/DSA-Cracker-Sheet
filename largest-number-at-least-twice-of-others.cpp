class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = INT_MIN;
        int maxPosition = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxi){
                maxPosition = i;
                maxi = nums[i];
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] != maxi && maxi < 2*nums[i]){
                return -1;
            }
        }
        return maxPosition;
    }
};
