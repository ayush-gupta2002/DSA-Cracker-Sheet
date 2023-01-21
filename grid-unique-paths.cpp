//MEMOIZATION APPROACH
class Solution {
public:

    bool isValid(int n,int m,int cRow,int cCol){
        if(cRow >= 0 && cCol >= 0 && cRow < m && cCol < n){
            return true;
        }
        return false;
    }

    int solve(int m,int n,int cRow,int cCol,set<vector<pair<int,int>>>& s, vector<pair<int,int>>& currentPath,vector<int>& dp){
        if(cRow == m-1 && cCol == n-1){
            if(s.find(currentPath) == s.end()){
                s.insert(currentPath);
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[(cRow*n) + cCol] != -1){
            return dp[(cRow*n) + cCol];
        }

        currentPath.push_back({cRow,cCol});
        int delRow[] = {0,1};
        int delCol[] = {1,0};
        int res = 0;

        for(int i=0;i<2;i++){
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];

            if(isValid(n,m,nRow,nCol)){
                res+= solve(m,n,nRow,nCol,s,currentPath,dp);
            }
        }
        dp[(cRow*n) + cCol] = res;
        return res;


    }

    int uniquePaths(int m, int n) {
        set<vector<pair<int,int>>> s;
        vector<pair<int,int>> currentPath;
        vector<int> dp(m*n,-1);
        return solve(m,n,0,0,s,currentPath,dp);
    }
};

//TABULATION APPROACH
class Solution {
public:

    bool isValid(int n,int m,int cRow,int cCol){
        if(cRow >= 0 && cCol >= 0 && cRow < m && cCol < n){
            return true;
        }
        return false;
    }

    int solve(int m,int n,int cRow,int cCol,set<vector<pair<int,int>>>& s, vector<pair<int,int>>& currentPath,vector<int>& dp){
        if(cRow == m-1 && cCol == n-1){
            if(s.find(currentPath) == s.end()){
                s.insert(currentPath);
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[(cRow*n) + cCol] != -1){
            return dp[(cRow*n) + cCol];
        }

        currentPath.push_back({cRow,cCol});
        int delRow[] = {0,1};
        int delCol[] = {1,0};
        int res = 0;

        for(int i=0;i<2;i++){
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];

            if(isValid(n,m,nRow,nCol)){
                res+= solve(m,n,nRow,nCol,s,currentPath,dp);
            }
        }
        dp[(cRow*n) + cCol] = res;
        return res;


    }

    int uniquePaths(int m, int n) {
        vector<int> dp(m*n,-1);
        dp[0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0] = 1;
                }
                else{
                    int left = 0;
                    int right = 0;
                    if(i > 0){
                        left = dp[(i-1)*n + j];
                    }
                    if(j > 0){
                        right = dp[i*n + (j-1)];
                    }
                    dp[i*n + j] = left+right;
                }
            }
        }
        return dp[m*n -1];
    }
};
