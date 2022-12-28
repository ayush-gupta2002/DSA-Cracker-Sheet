//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool isValid(int i,int j,int n,int m){
      if(i>=0 && i<n && j>=0 && j<m){
          return true;
      }
      return false;
  }
  
  void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,vector<pair<int,int>>& toPush,int base_row,int base_col){
      int n = grid.size();
      int m = grid[0].size();
      visited[i][j] = 1;
      pair<int,int> p = make_pair(i - base_row,j - base_col);
      toPush.push_back(p);
      
      int delRow[] = {-1,0,1,0};
      int delCol[] = {0,1,0,-1};
      
      for(int k=0;k<4;k++){
          int nRow = i + delRow[k];
          int nCol = j + delCol[k];
          
          if(isValid(nRow,nCol,n,m) && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0){
              dfs(nRow,nCol,grid,visited,toPush,base_row,base_col);
          }
      }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> >visited(n, vector<int> (m,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> toPush;
                    dfs(i,j,grid,visited,toPush,i,j);
                    s.insert(toPush);
                }
            }
        }
        return s.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
