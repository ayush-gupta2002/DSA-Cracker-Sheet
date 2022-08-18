class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash_map;
        int n = strs.size();
        
        for(int i = 0;i<n;i++){
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            hash_map[strs[i]].push_back(temp);
        }
        vector<vector<string>> answer;
        for(auto i:hash_map){
            answer.push_back(i.second);
        }
        return answer;
    }
};
