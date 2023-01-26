//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9 + 7;
    
int solve(vector<int>& num, int tar, int curri,vector<vector<int>>& dp){
    if(curri == 0){
        if(num[curri] == 0 && tar == 0){
            return 2;
        }
        else if(tar == 0 || tar == num[0]){
            return 1;
        }
        return 0;
    }
    if(dp[curri][tar] != -1){
        return dp[curri][tar];
    }

    int left = 0;
    if(num[curri] <= tar){
        left = solve(num,tar - num[curri],curri-1,dp);
    }
    int right = solve(num,tar,curri-1,dp);

    return dp[curri][tar] = (left + right) %mod;
}
    
    int countPartitions(int n, int d, vector<int>& num) {
        int totSum = 0;
        for(int it:num){
            totSum += it;
        }
        if(totSum-d < 0 || (totSum-d) % 2 != 0){
            return 0;
        }
        int tar = (totSum - d)/2;
    vector<vector<int>> dp(n, vector<int> (tar+1,-1));
    return solve(num,tar,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
