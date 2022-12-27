class Solution {
public:

    bool isValid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > visited(n, vector<int> (m,0));

        queue<pair<pair<int,int>,int> >q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && mat[i][j]==0){
                    pair<int,int> p = make_pair(i,j);
                    visited[i][j] = 1;
                    q.push({p,1});
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        vector<vector<int>> res(n,vector<int> (m,0));

        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            int row = p.first.first;
            int col = p.first.second;
            int distance = p.second;

            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow,nCol,n,m) && visited[nRow][nCol]==0 && mat[nRow][nCol] == 1){
                    res[nRow][nCol] = distance;
                    pair<pair<int,int>,int> p = {{nRow,nCol},distance+1};
                    q.push(p);
                    visited[nRow][nCol] = 1;

                }
            }
        }
        return res;
    }
};
