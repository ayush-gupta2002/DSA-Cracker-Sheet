class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n = nums.size();
        int count = 0;
        int maxCount = 0;

        while(i<n && j < n){
            if(nums[j] == 1){
                count++;
                j++;
            }
            else if(k > 0){
                k--;
                j++;
                count++;
            }
            else{
                if(nums[i] == 0){
                    k++;
                }
                i++;
                maxCount = max(maxCount,count);
                count--;

            }
        }
        maxCount = max(maxCount,count);
        return maxCount;
    }
};
