class Solution {
public:
    
    void getSubsequence(vector<vector<int>> &res, int currentTarget,int index, vector<int>& candidates, vector<int>& currentDs, int n){
        for(auto i:currentDs){
            cout<<i<<" ";
        }cout<<endl;
        if(currentTarget==0){
                res.push_back(currentDs);
                return;
        }
        for(int i = index;i<n;i++){
            if(i > index && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>currentTarget){
                break;
            }
            currentDs.push_back(candidates[i]);
            getSubsequence(res,currentTarget-candidates[i],i+1,candidates,currentDs,n);
            currentDs.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> currentDs;
        int n = candidates.size();
        getSubsequence(res,target,0,candidates,currentDs,n);
        return res;
    }
};
