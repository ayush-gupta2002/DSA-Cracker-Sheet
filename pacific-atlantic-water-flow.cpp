class Solution {
public:

    bool isValid(int row,int col,int n,int m){
        if(row >= 0 && row < n && col >= 0 && col < m){
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>>& visited, int row, int col, vector<vector<int>>& heights){
        visited[row][col] = 1;
        int n = heights.size();
        int m = heights[0].size();

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(isValid(nRow,nCol,n,m) && heights[nRow][nCol] >= heights[row][col] && visited[nRow][nCol] == 0){
                dfs(visited,nRow,nCol,heights);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> atlantic(n, vector<int> (m,0));
        vector<vector<int>> pacific(n, vector<int> (m,0));          
        vector<vector<int>> res;

        for(int j=0;j<m;j++){
            if(!pacific[0][j]){
                dfs(pacific,0,j,heights);
            }
        }

        for(int i=0;i<n;i++){
            if(!pacific[i][0]){
                dfs(pacific,i,0,heights);
            }
        }

        for(int j=0;j<m;j++){
            if(!atlantic[n-1][j]){
                dfs(atlantic,n-1,j,heights);
            }
        }

        for(int i=0;i<n;i++){
            if(!atlantic[i][m-1]){
                dfs(atlantic,i,m-1,heights);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] == pacific[i][j] && atlantic[i][j] == 1){
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};
