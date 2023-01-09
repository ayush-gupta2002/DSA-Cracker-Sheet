//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    bool isValid(int row,int col,int n){
        if(row >= 0 && col < n && row < n && col >= 0){
            return true;
        }
        return false;
    }
    
    bool dfs(int i,int j,vector<vector<int>>& visited, vector<vector<int>>& grid){
        int n = grid.size();
        visited[i][j] = 1;
        if(grid[i][j] == 2){
            return true;
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];
            
            if(isValid(nRow,nCol,n) && grid[nRow][nCol] >=2 && !visited[nRow][nCol]){
                bool ans = dfs(nRow,nCol,visited,grid);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    bool ans = dfs(i,j,visited,grid);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends
