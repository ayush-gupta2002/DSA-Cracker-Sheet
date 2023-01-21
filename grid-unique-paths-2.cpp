//MEMOIZATION

class Solution {
public:

    bool isValid(int cRow,int cCol,int n,int m){
        if(cRow >= 0 && cRow < n && cCol >=0 && cCol < m){
            return true;
        }
        return false;
    }

    int solve(int n,int m,int cRow,int cCol,set<vector<int>>& s,vector<int>& currentPath,vector<vector<int>>& obstacleGrid,vector<int>& dp){
        if(obstacleGrid[cRow][cCol] == 1){
            dp[cRow*m + cCol] = 0;
            return 0;
        }
        if(cRow == n-1 && cCol == m-1 && obstacleGrid[cRow][cCol] != 1){
            if(s.find(currentPath) == s.end()){
                s.insert(currentPath);
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[cRow*m + cCol] != -1){
            return dp[cRow*m + cCol];
        }
        currentPath.push_back(cRow * m + cCol);
        int res = 0;

        int delRow[] = {1,0};
        int delCol[] = {0,1};

        for(int i=0;i<=1;i++){
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];

            if(isValid(nRow,nCol,n,m) && obstacleGrid[nRow][nCol] != 1){
                res += solve(n,m,nRow,nCol,s,currentPath,obstacleGrid,dp);
            }
        }
        dp[cRow*m + cCol] = res;
        return res;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        set<vector<int>> s;
        vector<int> currentPath;
        vector<int> dp(n * m,-1);

        return solve(n,m,0,0,s,currentPath,obstacleGrid,dp);
    }
};

//TABULATION APPROACH

class Solution {
public:

    bool isValid(int cRow,int cCol,int n,int m){
        if(cRow >= 0 && cRow < n && cCol >=0 && cCol < m){
            return true;
        }
        return false;
    }

    int solve(int n,int m,int cRow,int cCol,set<vector<int>>& s,vector<int>& currentPath,vector<vector<int>>& obstacleGrid,vector<int>& dp){
        if(obstacleGrid[cRow][cCol] == 1){
            dp[cRow*m + cCol] = 0;
            return 0;
        }
        if(cRow == n-1 && cCol == m-1 && obstacleGrid[cRow][cCol] != 1){
            if(s.find(currentPath) == s.end()){
                s.insert(currentPath);
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[cRow*m + cCol] != -1){
            return dp[cRow*m + cCol];
        }
        currentPath.push_back(cRow * m + cCol);
        int res = 0;

        int delRow[] = {1,0};
        int delCol[] = {0,1};

        for(int i=0;i<=1;i++){
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];

            if(isValid(nRow,nCol,n,m) && obstacleGrid[nRow][nCol] != 1){
                res += solve(n,m,nRow,nCol,s,currentPath,obstacleGrid,dp);
            }
        }
        dp[cRow*m + cCol] = res;
        return res;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(n * m,0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 && j==0) && obstacleGrid[i][j] != 1){
                    dp[i*m + j] = 1;
                }
                else if(obstacleGrid[i][j] ==1){
                    dp[i*m + j] = 0;
                }
                else{
                    int left = 0;
                    int right = 0;
                
                    if(i > 0){
                        left = dp[(i-1)*m + j];
                    }
                    if(j > 0){
                        right = dp[i*m + (j-1)];
                    }
                    dp[i*m + j] = left+right;
                }
            }
        }
        return dp[(m*n) - 1];
    }
};
