class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currentMin = 1;
        int currentMax = 1;
        int res = *max_element(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                currentMin = 1;
                currentMax = 1;
                continue;
            }
            else{
                int temp = currentMax * nums[i];
                currentMax = max({currentMax*nums[i],nums[i],currentMin*nums[i]});
                currentMin = min({temp,nums[i],currentMin*nums[i]});
                res = max({res,currentMax,currentMin});
            }
        }
        return res;
    }
};
