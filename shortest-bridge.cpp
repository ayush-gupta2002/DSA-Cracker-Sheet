class Solution {
public:

    bool isValid(int row,int col,int n){
        if(row >= 0 && row < n && col >=0 && col < n){
            return true;
        }
        return false;
    }

    void firstIsland(vector<vector<int>>& grid,queue<pair<int,pair<int,int>>>& q,int i,int j,vector<vector<int>>& visited){
        q.push({0,{i,j}});
        int n = grid.size();
        visited[i][j] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];

            if(isValid(nRow,nCol,n) && !visited[nRow][nCol] && grid[nRow][nCol] == 1){
                firstIsland(grid,q,nRow,nCol,visited);
            }
        }

    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n && q.size() == 0;i++){
            for(int j=0;j<n && q.size() == 0;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    firstIsland(grid,q,i,j,visited);
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){
            pair<int,pair<int,int>> frontPair = q.front();
            q.pop();
            int currentLength = frontPair.first;
            pair<int,int> currentCell = frontPair.second;
            int cRow = currentCell.first;
            int cCol = currentCell.second;

            for(int i=0;i<4;i++){
                int nRow = delRow[i] + cRow;
                int nCol = delCol[i] + cCol;

                if(isValid(nRow,nCol,n) && grid[nRow][nCol] == 1 && !visited[nRow][nCol]){
                    return currentLength;
                }
                else if(isValid(nRow,nCol,n) && grid[nRow][nCol] == 0 && !visited[nRow][nCol]){
                    visited[nRow][nCol] = 1;
                    q.push({currentLength+1,{nRow,nCol}});
                }
            }
        }
        return -1;


    }
};
