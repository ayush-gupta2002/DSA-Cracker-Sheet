//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    bool isValid(int row,int col,int n,int m){
        if(row >=0 && row<n && col>=0 && col<m){
            return true;
        }
        return false;
    }
  
    void makeSet(vector<int>& parent,vector<int>& rank,int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(vector<int>& parent,int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = findParent(parent,parent[i]);
    }
    
    void unionSet(vector<int>& parent,vector<int>& rank,int u,int v,int n){
        int uParent = findParent(parent,u);
        int vParent = findParent(parent,v);
        
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
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int nodes = (n*m);
        vector<vector<int>> visited(n, vector<int> (m,0));
        vector<int> parent(nodes);
        vector<int> rank(nodes);
        makeSet(parent,rank,nodes);
        int count = 0;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        vector<int> res;
        
        for(vector<int> op:operators){
            int cRow = op[0];
            int cCol = op[1];
            if(visited[cRow][cCol]){
                res.push_back(count);
                continue;
            }
            count++;
            visited[cRow][cCol] = 1;
            for(int i=0;i<4;i++){
                int nRow = cRow + delRow[i];
                int nCol = cCol + delCol[i];
                if(isValid(nRow,nCol,n,m) && visited[nRow][nCol]){
                    int cNode = (cRow*m) + cCol;
                    int cParent = findParent(parent,cNode);
                    int nNode = (nRow*m) + nCol;
                    int nParent = findParent(parent,nNode);
                    
                    if(nParent != cParent){
                        unionSet(parent,rank,nNode,cNode,nodes);
                        count--;
                    }
                }
            }
        res.push_back(count);
    }
    return res;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
