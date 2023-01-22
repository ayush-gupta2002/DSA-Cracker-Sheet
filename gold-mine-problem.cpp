//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int n,int m,vector<vector<int>>& M, vector<vector<int>>&dp,int cRow,int cCol){
        if(cRow<0 || cRow>=n || cCol<0 || cCol>=m){
            return 0;
        }
        if(cCol == m-1){
            return M[cRow][m-1];
        }
        
        if(dp[cRow][cCol] != -1){
            return dp[cRow][cCol];
        }
        
        int nCol = cCol + 1;
        int maxi = 0;
        
        for(int delRow=-1;delRow<=1;delRow++){
            int nRow = delRow + cRow;
            maxi = max(maxi, M[cRow][cCol] + solve(n,m,M,dp,nRow,nCol));
        }
        return dp[cRow][cCol] = maxi;
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int> (m,-1));
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, solve(n,m,M,dp,i,0));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
