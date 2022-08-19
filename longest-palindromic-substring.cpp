class Solution {
public:
    
    int expandFromMiddle(string S, int right,int left){
        
        if(right<left || S==""){
            return 0;
        }
        
        while(left>=0 && right<S.length() && S[left]==S[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    
    string longestPalindrome(string s) {
        
        if(s==""){
            return "";
        }
        
        int start = 0;
        int end = 0;
        
        for(int i=0;i<s.length();i++){
            int len1 = expandFromMiddle(s,i,i);
            int len2 = expandFromMiddle(s,i+1,i);
            int currentMax = max(len1,len2);
            
            if(currentMax > end-start){
                start = i - ((currentMax-1)/2);
                end = i + (currentMax/2);
            }
        }
        return s.substr(start,end-start+1);
    }
};
