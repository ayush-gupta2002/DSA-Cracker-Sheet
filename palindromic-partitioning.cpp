class Solution {
public:
    
    bool isPalindrome(int start,int end,string &s){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void palindromePartition(string &s, int index, vector<vector<string>>& res,vector<string>& currentDs){
        if(index == s.size()){
            res.push_back(currentDs);
            return;
        }
        
        for(int i=index;i<s.size();++i){
            if(isPalindrome(index,i,s)){
                currentDs.push_back(s.substr(index,i-index+1));
                palindromePartition(s,i+1,res,currentDs);
                currentDs.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currentDs;
        palindromePartition(s,0,res,currentDs);
        return res;
    }
};
