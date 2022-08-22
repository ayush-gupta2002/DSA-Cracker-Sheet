class Solution {
public:
    
    
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s = countAndSay(n-1);
        string currentString = "";
        int frequency = 1;
        int element = s[0];
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1 || s[i+1]!=s[i]){
                char ch = frequency+48;
                cout<<"Element "<<element<<" Frequency "<<ch<<endl;
                currentString.push_back(ch);
                currentString.push_back(element);
                element = s[i+1];
                frequency=1;
                
            }
            else{
                frequency++;
            }
        }
        cout<<currentString<<endl;
        return currentString;
        
    }
};
