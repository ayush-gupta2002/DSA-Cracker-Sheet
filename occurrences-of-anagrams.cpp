class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        int n = s.length();
        int k = p.length();
        unordered_map<char,int> hash_map;
        for(auto &i:p){
            hash_map[i]++;
        }
        int distinct_letters = hash_map.size();
        int i=0;
        int j=0;
        while(j<n){
            if(hash_map.find(s[j])!=hash_map.end()){
                hash_map[s[j]]--;
                if(hash_map[s[j]]==0){
                    distinct_letters--;
                }
            }
            if((j-i+1)<k){
            }
            else if((j-i+1)==k){
                if(distinct_letters==0){
                    indices.push_back(i);
                }
                if(hash_map.find(s[i])!=hash_map.end()){
                    hash_map[s[i]]++;
                    if(hash_map[s[i]]==1){
                        distinct_letters++;
                    }
                }
                i++;
            }
            j++;
        }
        return indices;
        
    }
};
