class Solution {
public:
    bool isValid(int row,int col,int n){
        if(row >= 0 && col >= 0 && row < n && col < n){
            return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        //s -> maxTime till now, {row,col}
        set<pair<int,pair<int,int>>> s;
        s.insert({grid[0][0],{0,0}});
        vector<vector<int>> time(n, vector<int> (n,INT_MAX));
        time[0][0] = 0;
        int delRow[] = {0,1,0,-1};
        int delCol[] = {-1,0,1,0};

        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(s.begin());
            int cRow = p.second.first;
            int cCol = p.second.second;
            int cTime = p.first;
            if(cRow == n-1 && cCol == n-1){
                return cTime;
            }
            for(int i=0;i<4;i++){
                int nRow = cRow + delRow[i];
                int nCol = cCol + delCol[i];

                if(isValid(nRow,nCol,n)){
                    int updatedMax = max(cTime, grid[nRow][nCol]);
                    if(updatedMax < time[nRow][nCol]){
                        time[nRow][nCol] = updatedMax;
                        s.insert({updatedMax, {nRow,nCol}});
                    }
                }
            }
        }
        return -1;
    }
};
