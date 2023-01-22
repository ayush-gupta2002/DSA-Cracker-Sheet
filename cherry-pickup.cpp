class Solution {
public:

    int solve(vector<vector<int>>& grid, int n,int i1,int j1,int i2,int j2,vector<vector<vector<vector<int>>>>& dp){

        if(i1>n-1 || j1>n-1 || i2>n-1 || j2>n-1 || grid[i1][j1] == -1 || grid[i2][j2] == -1){
            return INT_MIN;
        }

        else if(dp[i1][j1][i2][j2] != -1){
            return dp[i1][j1][i2][j2];
        }

        else if(i1 == n-1 && j1 == n-1){
            return grid[i1][j1];
        }

        else if(i2 == n-1 && j2 == n-1){
            return grid[i2][j2];
        }

        int maxi = -1e8;


        int delRow[] = {0,1};
        int delCol[] = {1,0};

        for(int i=0;i<2;i++){
            int nRow1 = i1 + delRow[i];
            int nCol1 = j1 + delCol[i];

            for(int j=0;j<2;j++){
                int nRow2 = i2 + delRow[j];
                int nCol2 = j2 + delCol[j];

                if(i1 == i2 && j1 == j2){
                    maxi = max(maxi, grid[i1][j1] + solve(grid,n,nRow1,nCol1,nRow2,nCol2,dp));
                }
                else{
                    maxi = max(maxi, grid[i1][j1] + grid[i2][j2] + solve(grid,n,nRow1,nCol1,nRow2,nCol2,dp));
                }
            }
        }

        return dp[i1][j1][i2][j2] = maxi;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>> (n, vector<int> (n,-1))));
        return max(0,solve(grid,n,0,0,0,0,dp));
    }
};
