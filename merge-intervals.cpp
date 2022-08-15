class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n==0){
            return res;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> current_interval = intervals[0];
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=current_interval[0] && intervals[i][0]<=current_interval[1]){
                current_interval[1] = max(intervals[i][1],current_interval[1]);
            }
            else{
                res.push_back(current_interval);
                current_interval = intervals[i];
            }
        }
        res.push_back(current_interval);
        return res;
    }
};
