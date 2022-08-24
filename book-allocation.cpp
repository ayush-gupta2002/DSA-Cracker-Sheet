//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isPossible(int A[],int N,int M,int mid){
        int i = 0;
        int studentCount = 1;
        int currentSum = 0;
        for(;i<N;++i){
            if((currentSum+A[i])<=mid){
                currentSum+=A[i];
            }
            else{
                studentCount++;
                if(studentCount>M || A[i]>mid){
                    return false;
                }
                currentSum = A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
        }
        int lo = 0;
        int hi = sum;
        int mid = lo + (hi-lo)/2;
        int ans = -1;
        
        while(lo<=hi){
            if(isPossible(A,N,M,mid)){
                ans = mid;
                hi = mid -1;
            }
            else{
                lo = mid+1;
            }
            mid = lo + (hi-lo)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
