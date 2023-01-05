class Solution {
public:

    bool isValid(int row,int col,int m,int n){
        if(row >= 0 && row < m && col>=0 && col<n){
            return true;
        }
        return false;
    }

    void dfs(int& currentArea, vector<vector<int>>& grid, int i, int j,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = 1;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];

            if(isValid(nRow,nCol,m,n) && grid[nRow][nCol] == 1 && !visited[nRow][nCol]){
                currentArea++;
                dfs(currentArea, grid, nRow, nCol, visited);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m , vector<int> (n,0));

        int maxArea = INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int currentArea = 1;
                    dfs(currentArea,grid,i,j,visited);
                    maxArea = max(maxArea,currentArea);
                }
            }
        }
        if(maxArea == INT_MIN){
            return 0;
        }
        return maxArea;
    }
};
