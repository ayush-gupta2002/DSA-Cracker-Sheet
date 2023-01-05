class Solution {
public:

    void makeSet(vector<int>& rank,vector<int>& parent,int n){
        for(int i=0;i<n;i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(vector<int>& parent,int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = findParent(parent,parent[i]);
    }

    void unionSet(vector<int>& parent, int u,int v,vector<int>& rank,int& extraEdges){
        int uParent = findParent(parent,u);
        int vParent = findParent(parent,v);
        if(uParent == vParent){
            extraEdges++;
        }

        int uParentRank = rank[uParent];
        int vParentRank = rank[vParent];

        if(uParentRank < vParentRank){
            parent[uParent] = vParent;
            rank[vParent]++;
        }
        else if(uParentRank >= vParentRank){
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n);

        makeSet(rank,parent,n);
        int extraEdges = 0;

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            unionSet(parent,u,v,rank,extraEdges);
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(findParent(parent,i) == i){
                components++;
            }
        }
        cout<<"components "<<components<<" "<<"extraEdges "<<extraEdges<<endl;
        if(extraEdges >= components - 1){
            return components-1;
        }
        return -1;
    }
};
