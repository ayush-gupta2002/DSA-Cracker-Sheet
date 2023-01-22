#include <bits/stdc++.h> 
using namespace std;


int solve(int r,int c,vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>>& dp){
    if(i<0 || i>=r || j1<0 || j1>=c || j1<0 || j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int delCol[] = {-1,0,1};
    int res = -1e8;

    for(int k=0;k<3;k++){
        int nCol1 = j1 + delCol[k]; 
        for(int m=0;m<3;m++){
            int nCol2 = j2 + delCol[m];

            
            if(j1 == j2){
                res = max(res, grid[i][j1] + solve(r,c,grid,i+1,nCol1,nCol2,dp));
            }
            else{
                res = max(res, grid[i][j1] + grid[i][j2] + solve(r,c,grid,i+1,nCol1,nCol2,dp));
            }
        }
    }
    return dp[i][j1][j2] = res;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c, vector<int> (c,-1)));
    return solve(r,c,grid,0,0,c-1,dp);
}
