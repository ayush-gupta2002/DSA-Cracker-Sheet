class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        if(i<n && i>=0 && j<m && j>=0){
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int> > visited(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }

        int res = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){

            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int row = p.first.first;
            int col = p.first.second;

            int currentTime = p.second;
            res = max(res,currentTime);

            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow,nCol,n,m) && visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1){
                    q.push({{nRow,nCol},currentTime+1});
                    visited[nRow][nCol] = 2;
                }
            }



        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && visited[i][j] != 2){
                    return -1;
                }
            }
        }

        return res;
    }
};
