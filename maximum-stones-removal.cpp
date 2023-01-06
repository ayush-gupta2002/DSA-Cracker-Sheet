//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;

        for(vector<int> stone:stones){
            maxRow = max(maxRow,stone[0]);
            maxCol = max(maxCol,stone[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int,int> stoneNodes;

        for(vector<int> stone:stones){
            int cRow = stone[0];
            int cCol = stone[1] + maxRow + 1;

            ds.unionBySize(cRow,cCol);
            stoneNodes[cRow] = 1;
            stoneNodes[cCol] = 1;
        }

        int count = 0;

        for(pair<int,int> it:stoneNodes){
            if(ds.findParent(it.first) == it.first){
                count++;
            }
        }
        return n - count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
