//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        long long ans = 0;
        
        while(!pq.empty()){
            long long x1 = pq.top();
            pq.pop();
            if(pq.empty()){
                break;
            }
            long long x2 = pq.top();
            pq.pop();
            ans += (x1 + x2);
            pq.push(x1 + x2);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
