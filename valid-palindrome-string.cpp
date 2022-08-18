class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string new_str = "";
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                new_str.push_back(tolower(s[i]));
            }
            else if(isdigit(s[i])){
                new_str.push_back(s[i]);
            }
        }
        int i = 0;
        int j = new_str.size()-1;
        cout<<new_str;
        while(i<j){
            if(new_str[i]==new_str[j] && i!=j){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        cout<<"new string "<<new_str;
        return true;
    }
};
