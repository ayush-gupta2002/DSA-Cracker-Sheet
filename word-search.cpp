class Solution {
public:

    bool isValid(int row,int col,int n,int m){
        if(row >= 0 && row < n && col >= 0 && col < m){
            return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& visited,int i,int j,int currentIndex, vector<vector<char>>& board, int n, int m, string word){
        if(currentIndex == word.size() - 1){
            return true;
        }
        visited[i][j] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        for(int k=0;k<4;k++){
            int nRow = i + delRow[k];
            int nCol = j + delCol[k];

            if(isValid(nRow,nCol,n,m) && !visited[nRow][nCol] && board[nRow][nCol] == word[currentIndex+1]){
                bool res = dfs(visited,nRow,nCol,currentIndex+1,board,n,m,word);
                if(res){
                    return true;
                }
            }
        }
        visited[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && (board[i][j] == word[0])){
                    bool res = dfs(visited,i,j,0,board,n,m,word);
                    if(res){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
