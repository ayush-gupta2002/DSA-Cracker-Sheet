class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productWithoutZero = 1;
        int productWithZero = 1;
        int countZeroes = 0;
        for(int it:nums){
            if(it == 0 && countZeroes < 1){
                productWithZero = 0;
                countZeroes++;
                continue;
            }
            else if(it == 0 && countZeroes >= 1){
                productWithoutZero = 0;
                countZeroes++;
                continue;
            }
            productWithoutZero *= it;
            productWithZero *= it;
        }

        vector<int> ans(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                ans[i] = productWithoutZero;
            }
            else{
                ans[i] = productWithZero/nums[i];
            }
        }
        return ans;
    }
};
