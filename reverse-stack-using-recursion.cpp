//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void insertAtBottom(stack<int>& st,int temp){
        if(st.empty()){
            st.push(temp);
            return;
        }
        
        int x = st.top();
        st.pop();
        insertAtBottom(st,temp);
        st.push(x);
        
    }
    
    stack<int> Reverse(stack<int>& St){
        if(St.empty()){
            return St;
        }
        
        int temp = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St,temp);
        
        return St;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int>res;
        while(ans.size())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
