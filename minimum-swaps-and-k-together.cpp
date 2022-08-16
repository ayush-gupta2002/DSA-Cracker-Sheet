//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int window_size = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                window_size ++;
            }
        }
        int current_swaps = 0;
        int res = INT_MAX;
        int i=0;
        int j=0;
        
        while(j<window_size){
            if(arr[j]>k){
                current_swaps++;
            }
            j++;
        }
        
        res = current_swaps;
        i=0;
        j=window_size;
        
        while(j<n){
            if(arr[i]>k){
                current_swaps--;
            }
            if(arr[j]>k){
                current_swaps++;
            }
            res = min(res,current_swaps);
            j++;
            i++;
        }
        return res;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends
