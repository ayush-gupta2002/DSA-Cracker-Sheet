class Solution {
public:
    
    bool isSafe(int row,int col,unordered_map<int,int> leftRow,unordered_map<int,int> lowerDiagonal,unordered_map<int,int> upperDiagonal,int n){
        if(leftRow[row]==1 || upperDiagonal[n-1+col-row]==1 || lowerDiagonal[col+row]==1){
            return false;
        }
        return true;
    }
    
    void getBoards(vector<vector<string>>& answer,vector<string>& currentBoard, int n, int col,unordered_map<int,int> leftRow,unordered_map<int,int> lowerDiagonal, unordered_map<int,int> upperDiagonal){
        if(col==n){
            answer.push_back(currentBoard);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,leftRow,lowerDiagonal,upperDiagonal,n)){
                currentBoard[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                getBoards(answer,currentBoard,n,col+1,leftRow,lowerDiagonal,upperDiagonal);
                currentBoard[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        string s(n,'.');
        vector<string> currentBoard(n,s);
        unordered_map<int,int> leftRow;
        unordered_map<int,int> upperDiagonal;
        unordered_map<int,int> lowerDiagonal;
        getBoards(answer,currentBoard,n,0,leftRow,lowerDiagonal,upperDiagonal);
        return answer;
    }
};
