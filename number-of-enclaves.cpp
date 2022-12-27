class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }

    void dfs(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;

        int delCol[] = {-1,0,1,0};
        int delRow[] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];

            if(isValid(nRow,nCol,n,m) && !visited[nRow][nCol] && grid[nRow][nCol]==1){
                dfs(nRow,nCol,visited,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> >visited(n, vector<int> (m,0));
        int count = 0;

        for(int i=0;i<n;i++){
            if(visited[i][0] == 0 && grid[i][0] == 1){
                dfs(i,0,visited,grid);
            }
            if(visited[i][m-1] == 0 && grid[i][m-1] == 1){
                dfs(i,m-1,visited,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(visited[0][j] == 0 && grid[0][j] == 1){
                dfs(0,j,visited,grid);
            }
            if(visited[n-1][j] == 0 && grid[n-1][j] == 1){
                dfs(n-1,j,visited,grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }
};
