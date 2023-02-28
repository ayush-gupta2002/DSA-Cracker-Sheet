//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int n, int prices[]) {
        vector<vector<int>> current(2,vector<int> (K+1,0)), next(2,vector<int> (K+1,0));

        for(int curr=n-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap=1;cap<=K;cap++){

                    if(canBuy){
                        current[canBuy][cap] = max(next[0][cap]-prices[curr], next[1][cap]);
                    }
                    else{
                        current[canBuy][cap] = max(next[1][cap-1] + prices[curr], next[0][cap]);
                    }
                }
                next = current;
            }
        }

        return current[1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends
