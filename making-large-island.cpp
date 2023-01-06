class DisjointSet{
    public:
        int n;
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

        DisjointSet(int nodes){
            parent.resize(nodes+1);
            rank.resize(nodes+1);
            size.resize(nodes+1);
            n = nodes;
            for(int i=0;i<n;i++){
                size[i] = 1;
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findParent(int i){
            if(parent[i] == i){
                return i;
            }
            return parent[i] = findParent(parent[i]);
        }

        void unionSet(int u,int v){
            int uParent = findParent(u);
            int vParent = findParent(v);

            int uParentRank = rank[uParent];
            int vParentRank = rank[vParent];

            if(uParentRank >= vParentRank){
                parent[vParent] = uParent;
                rank[uParent]++;
            }
            else{
                parent[uParent] = vParent;
                rank[vParent]++;
            }
        }

        void unionBySize(int u, int v){
            int uParent = findParent(u);
            int vParent = findParent(v);

            int uParentSize = size[uParent];
            int vParentSize = size[vParent];

            if(uParent == vParent){
                return;
            }
            if(uParentSize <= vParentSize){
                parent[uParent] = vParent;
                size[vParent] += size[uParent];
            }
            else{
                parent[vParent] = uParent;
                size[uParent] += size[vParent];
            }
        }
};

bool isValid(int row,int col,int n){
    if(row>=0 && row<n && col>=0 && col<n){
        return true;
    }
    return false;
}

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int res = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cNode = (i*n) + j;
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int nRow = i + delRow[k];
                        int nCol = j + delCol[k];

                        if(isValid(nRow,nCol,n) && grid[nRow][nCol] == 1){
                            int nNode = (nRow * n) + nCol;
                            ds.unionBySize(nNode,cNode);
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    set<int> s;
                    for(int k=0;k<4;k++){
                        int nRow = i + delRow[k];
                        int nCol = j + delCol[k];

                        if(isValid(nRow,nCol,n) && grid[nRow][nCol] == 1){
                            int nNode = (nRow * n) + nCol;
                            int nNodeParent = ds.findParent(nNode);
                            s.insert(nNodeParent);
                        }
                    }
                    int currentArea = 1;
                    for(auto it:s){
                        currentArea += ds.size[it];
                    }
                    res = max(currentArea,res);
                }
            }
        }
        for(int i:ds.size){
            res = max(res,i);
        }
        return res;

        
    }
};
