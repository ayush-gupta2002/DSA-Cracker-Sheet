//MEMOIZATION

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int>& arr,int sum,int n,int curri,int currentSum, vector<vector<int>>& dp){
        if(currentSum == sum){
            return true;
        }
        else if(curri >= n){
            return false;
        }
        else if(currentSum > sum){
            return false;
        }
        
        if(dp[currentSum][curri] != -1){
            return dp[currentSum][curri];
        }
        
        bool left = solve(arr,sum,n,curri+1,currentSum,dp);
        bool right = solve(arr,sum,n,curri+1,currentSum + arr[curri],dp);
        if(left || right){
            return dp[currentSum][curri] = true;
        }
        return dp[currentSum][curri] = false;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(sum, vector<int> (n,-1));
        return solve(arr,sum,n,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

//TABULATION
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int> (k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int target = 1;target<=k;target++){
            bool left = false;
            if(target>=arr[i]){
                left = dp[i-1][target-arr[i]];
            }
            bool right = dp[i-1][target];
            if(left || right){
                dp[i][target] = true;
            }
            else{
                dp[i][target] = false;
            }
        }
    }
    return dp[n-1][k];
}
