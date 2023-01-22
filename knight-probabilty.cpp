class Solution {
public:

    double solve(int n,int k,int cRow,int cCol,int number,vector<vector<vector<double>>>& dp){
        if(cRow < 0 || cRow >= n || cCol < 0 || cCol >= n){
            return 0;
        }

        else if(number == k){
            return 1;
        }

        if(dp[number][cRow][cCol] != -1){
            return dp[number][cRow][cCol];
        }
        double sum = 0;
        
        //delRow = -1 --> +2, -2
            //.    +1 --> +2,-2
            //.    -2 --> -1,+1
            //.    +2 --> -1,+1

        int delRow[] = {-1,-1,1,1,-2,-2,2,2};
        int delCol[] = {2,-2,2,-2,-1,1,-1,1};

        for(int i=0;i<8;i++){
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];
            // cout<<nRow<<nCol<<delRow[i]<<delCol[i]<<endl;
            
            // if(solve(n,k,nRow,nCol,number+1)){
            //     cout<<nRow<<","<<nCol<<" "<<cRow<<","<<cCol<<endl;
            // }
            sum += solve(n,k,nRow,nCol,number+1,dp);
        }
        return dp[number][cRow][cCol] = sum/8;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k, vector<vector<double>> (n,vector<double>(n,-1)));
        return solve(n,k,row,column,0,dp);
    }
};
