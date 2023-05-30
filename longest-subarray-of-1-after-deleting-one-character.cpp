class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int k = 1;


        int i = 0;
        int j = 0;

        int maxCnt = 0;

        while(j<n && i<n){
            if(nums[j] == 0 && k == 1){
                j++;
                k--;
            }
            else if(nums[j] == 1){
                cnt++;
                j++;
            }
            else{
                if(nums[i] == 0){
                    k++;
                    i++;
                }else{
                    i++;
                    cnt--;
                }
            }
            maxCnt = max(maxCnt,cnt);
        }

        if(maxCnt == nums.size()){
            return maxCnt - 1;
        }
        return maxCnt;
    }
};
