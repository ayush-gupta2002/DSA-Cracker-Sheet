class Solution {
public:
    
    void getSubsequence(int index, int currentTarget, vector<int> &currentDs, vector<vector<int>> &res, vector<int>& candidates){
        if(index==candidates.size()){
            if(currentTarget==0){
                res.push_back(currentDs);
            }
            return;
        }
            
        if(candidates[index]<=currentTarget){
            //The element is picked
            currentDs.push_back(candidates[index]);
            getSubsequence(index,currentTarget - candidates[index],currentDs,res,candidates);
            currentDs.pop_back();
        }
            
        //The element is not picked
        getSubsequence(index+1,currentTarget,currentDs,res,candidates);
    }

public:    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currentDs;
        getSubsequence(0,target,currentDs,res,candidates);
        return res;
        
    }
};
