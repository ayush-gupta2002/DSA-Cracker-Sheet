//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& grid){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));

        while(!q.empty()){
            pair<int,int> topPair = q.front();
            int row = topPair.first;
            int col = topPair.second;
            q.pop();

            // if(row > 0){
            //     int above = grid[row-1][col];
            //     if(above == '1' && visited[row-1][col] == 0){
            //         q.push(make_pair(row-1,col));
            //         visited[row-1][col] = 1;
            //     }
            // }
            // if(row < grid.size()-1){
            //     int below = grid[row+1][col];
            //     if(below == '1' && visited[row+1][col] == 0){
            //         q.push(make_pair(row+1,col));
            //         visited[row+1][col] = 1;
            //     }
            // }
            // if(col < grid[0].size()-1){
            //     int right = grid[row][col+1];
            //     if(right == '1' && visited[row][col+1] == 0){
            //         q.push(make_pair(row,col+1));
            //         visited[row][col+1] = 1;
            //     }
            // }
            // if(col > 0){
            //     int left = grid[row][col-1];
            //     if(left == '1' && visited[row][col-1] == 0){
            //         q.push(make_pair(row,col-1));
            //         visited[row][col-1] =1 ;
            //     }
            // }
            // if(col>0 && row>0){
            //     int leftUpper = grid[row-1][col-1];
            //     if(leftUpper == '1' && visited[row-1][col-1] == 0){
            //         q.push(make_pair(row-1,col-1));
            //         visited[row-1][col-1] = 1;
            //     }
            // }
            // if(col>0 && row<grid.size()-1){
            //     int leftDown = grid[row+1][col-1];
            //     if(leftDown == '1' && visited[row+1][col-1] == 0){
            //         q.push(make_pair(row+1,col-1));
            //         visited[row+1][col-1] = 1;
            //     }
            // }
            // if(col < grid[0].size()-1 && row < grid.size()-1){
            //     int rightDown = grid[row+1][col+1];
            //     if(rightDown == '1' && visited[row+1][col+1] == 0){
            //         q.push(make_pair(row+1,col+1));
            //         visited[row+1][col+1] = 1;
            //     }
            // }
            // if(col < grid[0].size()-1 && row > 0){
            //     int rightUpper = grid[row-1][col+1];
            //     if(rightUpper == '1' && visited[row-1][col+1] == 0){
            //         q.push(make_pair(row-1,col+1));
            //         visited[row-1][col+1] = 1;
            //     }
            // }

            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol=-1;delCol<=1;delCol++){
                    int newRow = row + delRow;
                    int newCol = col + delCol;

                    if(newRow >=0 && newRow < grid.size() && newCol >=0 && newCol < grid[0].size() && grid[newRow][newCol] == '1' && visited[newRow][newCol] == 0){
                        visited[newRow][newCol] = 1;
                        q.push(make_pair(newRow,newCol));
                    }
                }
            }
        }

    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> visited(rows, vector<int> (columns,0));
        int count = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
