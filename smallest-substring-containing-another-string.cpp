class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash_map;
        for(char i:t){
            hash_map[i]++;
        }
        int count = hash_map.size();
        int n = s.length();
        int i = 0;
        int j = 0;
        int min_length = n;
        string res = "";
        while(j<n){
            if(hash_map.find(s[j]) != hash_map.end()){
                hash_map[s[j]]--;
                if(hash_map[s[j]]==0){
                    count--;
                }
            }
            
            if(count == 0){
                min_length = min(min_length,(j-i+1));
                if((j-i+1)<=min_length){
                    res = s.substr(i,(j-i+1));
                }
                while(count == 0){
                    if(hash_map.find(s[i]) == hash_map.end()){
                        i++;
                        min_length = min(min_length,(j-i+1));
                        if((j-i+1)<=min_length){
                            res = s.substr(i,(j-i+1));
                        }
                    }
                    else{
                        hash_map[s[i]]++;
                        if(hash_map[s[i]]>0){
                            count++;
                            i++;
                        }
                        else{
                            i++;
                            min_length = min(min_length,(j-i+1));
                            if((j-i+1)<=min_length){
                                res = s.substr(i,(j-i+1));
                            }
                        }
                    }
                }
                j++;
            }
            else if(count > 0){
                j++;
            }
        }
        cout<<min_length;
        return res;
    }
};
