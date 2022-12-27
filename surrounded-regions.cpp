class Solution {
public:

    bool isSurrounded(int i,int j,int n,int m,vector<vector<char>>& board,vector<vector<int>>& visited){
        int count = 0;
        int delCol[] = {-1,0,1,0};
        int delRow[] = {0,1,0,-1};

        if(!isBound(i,j,n,m)){
            for(int k=0;k<4;k++){
                int nRow = i+delRow[k];
                int nCol = j+delCol[k];
                if(board[nRow][nCol] == 'O' && visited[nRow][nCol] == 1){
                        return false;
                }

                if(isValid(nRow,nCol,n,m) && board[nRow][nCol] == 'X'){
                    count++;
                }
            }
        }
        if(count >=3){
            return true;
        }
        return false;
    }

    bool isValid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m){
            return true;
        }
        return false;
    }

    bool isBound(int i,int j,int n,int m){
        if(i==0 || i==n-1 || j==0 || j==m-1){
            return true;
        }
        return false;
    }

    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& visited){

        visited[i][j] = 1;

        int n = board.size();
        int m = board[0].size();

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j+ delCol[k];

            if(isValid(nRow,nCol,n,m) && visited[nRow][nCol] == 0 && board[nRow][nCol] == 'O'){
                dfs(nRow,nCol,board,visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(visited[i][0] == 0 && board[i][0] == 'O'){
                dfs(i,0,board,visited);
            }
            if(visited[i][m-1] == 0 && board[i][m-1] == 'O'){
                dfs(i,m-1,board,visited);
            }
        }
        for(int j=0;j<m;j++){
            if(visited[0][j] == 0 && board[0][j] == 'O'){
                dfs(0,j,board,visited);
            }
            if(visited[n-1][j] == 0 && board[n-1][j] == 'O'){
                dfs(n-1,j,board,visited);
            }
            
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
