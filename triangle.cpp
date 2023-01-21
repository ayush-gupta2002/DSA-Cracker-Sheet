//MEMOIZATION
class Solution {
public:

    bool isValid(int row,int col,vector<vector<int>>& triangle){
        if(row >= 0 && row < triangle.size() && col >=0 && col < triangle[row].size()){
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& triangle,int cRow,int cCol,vector<vector<int>>& dp){
        int n = triangle.size();
        int m = triangle[0].size();
        if(cRow == 0 && cCol == 0){
            return triangle[cRow][cCol];
        }

        if(dp[cRow][cCol] != -1){
            return dp[cRow][cCol];
        }

        int res = 1e9;
        int nRow = cRow - 1;
        for(int delCol=0;delCol<=1;delCol++){
            int nCol = cCol - delCol;
            if(isValid(nRow,nCol,triangle)){
                res = min(res,triangle[cRow][cCol] + solve(triangle,nRow,nCol,dp));
            }
        }
        dp[cRow][cCol] = res;
        return res;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = 1e9;
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++){
            for(int it:triangle[i]){
                dp[i].push_back(-1);
            }
        }

        for(int i=0;i<triangle[n-1].size();i++){
            ans = min(ans,solve(triangle,n-1,i,dp));
        }
        return ans;
    }
};

//TABULATION

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = 1e9;
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++){
            for(int it:triangle[i]){
                dp[i].push_back(-1);
            }
        }

        for(int i=0;i<triangle[n-1].size();i++){
            ans = min(ans,solve(triangle,n-1,i,dp));
        }
        return ans;
    }
