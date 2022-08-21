//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void pathFinder(vector<vector<int>>& m,int row,int col, vector<string>& res, string currentString,vector<vector<int>>& visited){
        if(row==(m.size()-1) && col==(m[0].size()-1)){
            res.push_back(currentString);
            return;
        }
        
        if(row+1<m.size() && m[row+1][col]==1 && visited[row+1][col]==0){
            currentString.push_back('D');
            visited[row][col]=1;
            pathFinder(m,row+1,col,res,currentString,visited);
            visited[row][col]=0;
            currentString.pop_back();
        }
        
        //left
        if(col-1>=0 && m[row][col-1]==1 && visited[row][col-1]==0){
            currentString.push_back('L');
            visited[row][col] = 1;
            pathFinder(m,row,col-1,res,currentString,visited);
            visited[row][col]=0;
            currentString.pop_back();
        }
        
        //right
        if(col+1<m[0].size() && m[row][col+1]==1 && visited[row][col+1]==0){
            currentString.push_back('R');
            visited[row][col]=1;
            pathFinder(m,row,col+1,res,currentString,visited);
            visited[row][col]=0;
            currentString.pop_back();
        }
        
        if(row-1>=0 && m[row-1][col]==1 && visited[row-1][col]==0){
            currentString.push_back('U');
            visited[row][col]=1;
            pathFinder(m,row-1,col,res,currentString,visited);
            visited[row][col]=0;
            currentString.pop_back();
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string currentString = "";
        vector<string> res;
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(m[0][0]==1){
            pathFinder(m,0,0,res,currentString,visited);
        }
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
