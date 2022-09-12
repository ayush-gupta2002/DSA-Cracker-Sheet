//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> myStack;
        for(int i=0;i<s.length();i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){
                myStack.push(s[i]);
            }
            else{
                if(s[i] == ')'){
                        bool isRedundant = true;
                        while(myStack.top() != '('){
                            if(myStack.top() == '+' || myStack.top() == '-' || myStack.top() == '*' || myStack.top() == '/'){
                                isRedundant = false;
                            }
                            myStack.pop();
                        }
                        if(isRedundant){
                            return true;
                        }
                        myStack.pop();
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
