//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    bool knows(vector<vector<int>> M,int A,int B){
        if(M[A][B] == 1){
            return true;
        }
        return false;
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> myStack;
        for(int i=0;i<n;i++){
            myStack.push(i);
        }
        
        while(myStack.size() > 1){
            int A = myStack.top();
            myStack.pop();
            int B = myStack.top();
            myStack.pop();
            
            if(knows(M,A,B)){
                myStack.push(B);
            }
            else{
                myStack.push(A);
            }
        }
        
        int top_ele = myStack.top();
        bool rowCheck = true;
        bool colCheck = true;
        
        for(int i=0;i<n;i++){
            if(M[top_ele][i] == 1){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(M[i][top_ele] == 0 && i!=top_ele){
                return -1;
            }
        }
        return top_ele;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
