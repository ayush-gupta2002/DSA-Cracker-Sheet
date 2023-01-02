class Solution {
public:

    bool isValid(int row,int col,int n,int m){
        if(row>=0 && row<n && col>=0 && col<m){
            return true;
        }
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int> (n,INT_MAX));
        distance[0][0] = 0;
        queue<pair<int, pair<int,int>>> q;
        pair<int, pair<int,int>> p = {0,{0,0}};
        q.push(p);

        while(!q.empty()){
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            int cellDistance = p.first;
            int cRow = p.second.first;
            int cCol = p.second.second;
            
            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol = -1;delCol<=1;delCol++){
                    int nRow = delRow + cRow;
                    int nCol = delCol + cCol;
                    if(isValid(nRow,nCol,n,n) && grid[nRow][nCol] == 0){
                        int currentDistance = cellDistance + 1;
                        if(currentDistance < distance[nRow][nCol]){
                            // auto foundRecord = s.find({distance[nRow][nCol],{nRow,nCol}});
                            // if(foundRecord != s.end()){
                            //     s.erase(foundRecord);
                            // }
                            distance[nRow][nCol] = currentDistance;
                            q.push({currentDistance,{nRow,nCol}});
                        }
                    }
                }
            }
        }
        if(grid[0][0] == 1 || distance[n-1][n-1]==INT_MAX){
            return -1;
        }
        return distance[n-1][n-1]+1;

    }
};
