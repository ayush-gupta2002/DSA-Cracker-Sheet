class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash_map;
        
        int n = (int)nums.size();
        
        int prefix_sum = 0;
        
        int count=0;
        
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            
            if(prefix_sum == k)
                count++;
            
            if(hash_map.find(prefix_sum-k) != hash_map.end())
                count += hash_map[prefix_sum-k];
            
            hash_map[prefix_sum]++;
            
        }
        return count;
    }
};
