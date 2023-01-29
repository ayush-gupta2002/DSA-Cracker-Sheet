class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l<r){
            //l correct r incorrect
            if(nums[l]%2==0 && nums[r]%2==0){
                l++;
            }
            //l incorrect r incorrect
            else if(nums[l]%2!=0 && nums[r]%2==0){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                r--;
                l++;
            }
            //l correct r correct
            else if(nums[l]%2==0 && nums[r]%2!=0){
                l++;
                r--;
            }
            //l incorrect r correct
            else if(nums[l]%2!=0 && nums[r]%2!=0){
                r--;
            }
        }
        return nums;
    }
};
