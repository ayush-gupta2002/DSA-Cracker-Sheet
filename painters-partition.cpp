//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    bool isPossible(int arr[],int n,int k,long long mid){
        long long currentSum = 0;
        int i = 0;
        int painterCount = 1;
        for(;i<n;i++){
            if(currentSum + arr[i] <= mid){
                currentSum += arr[i];
            }
            else{
                painterCount ++;
                if(painterCount>k || arr[i]>mid){
                    return false;
                }
                currentSum = arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        long long lo = 0;
        long long hi = sum;
        long long mid = lo + (hi-lo)/2;
        long long ans=mid;
        
        while(lo<=hi){
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                hi = mid-1;
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
