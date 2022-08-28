class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int goalPost = nums.size()-1;
        int i=nums.size()-1;
        while(i>=0){
            if(goalPost-i<=nums[i]){
                goalPost = i;
            }
            i--;
        }
        if(goalPost == 0){
            return true;
        }
        return false;
    }
};
