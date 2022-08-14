class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest_streak = 0;
        unordered_map<int,int> hash_map;
        for(int i=0;i<n;i++){
            hash_map[nums[i]] = i;
        }
        for(int i=0;i<n;i++){
            if(hash_map.find(nums[i]-1)==hash_map.end()){
                int current_num = nums[i];
                int current_streak = 1;
                
                while(hash_map.find((current_num)+1)!=hash_map.end()){
                current_num++;
                current_streak++;
                }
                longest_streak = max(current_streak,longest_streak);
            }
        }
        return longest_streak;
    }
};
