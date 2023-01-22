class Solution {
public:

    int solve(vector<vector<int>>& grid,int r,int c,int i,int j1,int j2,vector<vector<vector<int>>>& dp){
        if(i<0 || i>=r || j1<0 || j1>=c || j2<0 || j2>=c){
            return -1e8;
        }

        if(i == r-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }

        int maxi = 0;
        int nRow = i+1;
        for(int delCol1=-1;delCol1<=1;delCol1++){
            int nCol1 = j1 + delCol1;
            for(int delCol2=-1;delCol2<=1;delCol2++){
                int nCol2 = j2 + delCol2;

                if(j1 == j2){
                    maxi = max(maxi, grid[i][j1] + solve(grid,r,c,nRow,nCol1,nCol2,dp));
                }
                else{
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(grid,r,c,nRow,nCol1,nCol2,dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c,-1)));
        return solve(grid,r,c,0,0,c-1,dp);
    }
};
