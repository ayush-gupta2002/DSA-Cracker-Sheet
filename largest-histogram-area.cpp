//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<long long int> nextSmallerElement(long long arr[],int n){
        vector<long long int> res;
        stack<long long int> myStack;
        myStack.push(-1);
        
        for(int i=n-1;i>=0;i--){
            while(myStack.top() != -1 && arr[myStack.top()] >= arr[i]){
                myStack.pop();
            }
            res.push_back(myStack.top());
            myStack.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    vector<long long int> prevSmallerElement(long long arr[],int n){
        vector<long long int> res;
        stack<long long int> myStack;
        myStack.push(-1);
        
        for(int i=0;i<n;i++){
            while(myStack.top() != -1 && arr[myStack.top()] >= arr[i]){
                myStack.pop();
            }
            res.push_back(myStack.top());
            myStack.push(i);
        }
        return res;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long int> next = nextSmallerElement(arr,n);
        vector<long long int> prev = prevSmallerElement(arr,n);
        long long int maxArea = 0;
        
        for(int i=0;i<n;i++){
            long long int l = arr[i];
            long long int b = next[i] - prev[i] - 1;
            if(next[i] == -1){
                b = n - prev[i] - 1;
            }
            long long int currentArea = l*b;
            if(currentArea > maxArea){
                maxArea = currentArea;
            }
        }
        return maxArea;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
