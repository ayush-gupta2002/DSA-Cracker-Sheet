class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> indices(27,-1);
        vector<int> res;
        for(int i=0;i<s.size();i++){
            indices[s[i] - 97] = i;
        }
        int maxi = 0;
        int prev = -1;

        for(int i=0;i<s.size();i++){
            maxi = max(maxi,indices[s[i]-97]);

            if(maxi == i){
                res.push_back(maxi-prev);
                prev = maxi;
            } 
        }
        
        return res;
    }
};
