class Solution {
public:

    bool isValid(int row,int col, int n,int m){
        if(row >= 0 && row < n && col >= 0 && col < m){
            return true;
        }
        return false;
    }

    bool dfs(int i, int j, vector<vector<int>>& grid2, vector<vector<int>>& grid1, vector<vector<int>>& visited, int n , int m,bool& check){
        visited[i][j] = 1;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];

            if(isValid(nRow,nCol,n,m) && !visited[nRow][nCol] && grid2[nRow][nCol] == 1){
                bool ans = dfs(nRow,nCol,grid2,grid1,visited,n,m,check);
                if(!ans){
                    check = false;
                }

            }
        }
        if(grid2[i][j] != grid1[i][j] && grid2[i][j] == 1){
            return false;
        }
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));
        int res = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid2[i][j] == 1 && grid1[i][j] == 1){
                    bool check = true;
                    bool ans = dfs(i,j,grid2,grid1,visited,n,m,check);
                    if(check){
                        res++;
                    }
                }

            }
        }

        return res;
    }
};
