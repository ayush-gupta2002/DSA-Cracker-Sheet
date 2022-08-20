class Solution {
public:
    
    void permutations(vector<int>& currentPermutation, int index,vector<vector<int>>& res,vector<int>& nums){
        if(index==nums.size()){
            res.push_back(currentPermutation);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            swap(currentPermutation[index],currentPermutation[i]);
            permutations(currentPermutation,index+1,res,nums);
            swap(currentPermutation[index],currentPermutation[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permutations(nums,0,res,nums);
        return res;
    }
};
