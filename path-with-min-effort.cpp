class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n, vector<int> (m,INT_MAX));
        effort[0][0] = 0;

        set<pair<int , pair<int,int>>> s;
        s.insert({0, {0,0}});

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(s.begin());
            int currentEffort = p.first;
            int cRow = p.second.first;
            int cCol = p.second.second;
            if(cRow == n-1 && cCol == m-1){
                return currentEffort;
            }

            for(int i=0;i<4;i++){
                int nRow = cRow + delRow[i];
                int nCol = cCol + delCol[i];

                if(isValid(nRow,nCol,n,m)){
                    int e = abs(heights[nRow][nCol] - heights[cRow][cCol]);
                    int maxEffort = max(e,currentEffort);
                    if(maxEffort < effort[nRow][nCol]){
                        effort[nRow][nCol] = maxEffort;
                        s.insert({maxEffort, {nRow,nCol}});
                    }
                }
                
            }
        }
        return -1;
    }
};
