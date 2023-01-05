class DisjointSet{
    public:
        int n;
        vector<int> parent;
        vector<int> rank;

        DisjointSet(int nodes){
            parent.resize(nodes+1);
            rank.resize(nodes+1);
            n = nodes;
            for(int i=0;i<n;i++){
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
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int> res(2);

        for(vector<int> edge:edges){
            int u = edge[0];
            int v = edge[1];
            cout<<u<<"->"<<ds.findParent(u)<<" "<<v<<ds.findParent(v)<<endl;

            if(ds.findParent(u) == ds.findParent(v)){
                res[0] = u;
                res[1] = v;
            }
            else{
                ds.unionSet(u,v);
            }
        }
        return res;
    }
};
