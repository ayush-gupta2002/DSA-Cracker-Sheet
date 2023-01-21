//MEMOIZATION

class Solution {
public:

    bool isValid(int cRow,int cCol,int n,int m){
        if(cRow >= 0 && cCol >= 0 && cRow < n && cCol < m){
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& grid,int n,int m,int cRow,int cCol,vector<vector<int>>& dp){

        if(cRow == 0 && cCol == 0){
            return grid[0][0];
        }
        if(dp[cRow][cCol] != -1){
            return dp[cRow][cCol];
        }

        int delRow[] = {0,1};
        int delCol[] = {1,0};
        int res = INT_MAX;

        for(int i=0;i<=1;i++){
            int nRow = cRow - delRow[i];
            int nCol = cCol - delCol[i];
            if(isValid(nRow,nCol,n,m)){
                res = min(res,solve(grid,n,m,nRow,nCol,dp) + grid[cRow][cCol]);
            }
        }
        dp[cRow][cCol] = res;
        return res;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(grid,n,m,n-1,m-1,dp);
    }
};

//TABULATION

class Solution {
public:

    bool isValid(int cRow,int cCol,int n,int m){
        if(cRow >= 0 && cCol >= 0 && cRow < n && cCol < m){
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& grid,int n,int m,int cRow,int cCol,vector<vector<int>>& dp){

        if(cRow == 0 && cCol == 0){
            return grid[0][0];
        }
        if(dp[cRow][cCol] != -1){
            return dp[cRow][cCol];
        }

        int delRow[] = {0,1};
        int delCol[] = {1,0};
        int res = INT_MAX;

        for(int i=0;i<=1;i++){
            int nRow = cRow - delRow[i];
            int nCol = cCol - delCol[i];
            if(isValid(nRow,nCol,n,m)){
                res = min(res,solve(grid,n,m,nRow,nCol,dp) + grid[cRow][cCol]);
            }
        }
        dp[cRow][cCol] = res;
        return res;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        dp[0][0] = grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[0][0] = grid[0][0];
                }
                else{
                    int left = 1e9;
                    int right = 1e9;

                    if(i>0){
                        left = dp[i-1][j];
                    }
                    if(j>0){
                        right = dp[i][j-1];
                    }
                    dp[i][j] = min(left,right) + grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
