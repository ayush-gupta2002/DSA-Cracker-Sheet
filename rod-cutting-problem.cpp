//MEMOIZATION

    int solve(int price[],int currentLength,int curri,vector<vector<int>>& dp){
        if(curri < 0){
            return 0;
        }
        if(currentLength <= 0){
            return 0;
        }
        
        if(dp[curri][currentLength] != -1){
            return dp[curri][currentLength];
        }
        
        int left = 0;
        if(currentLength >= (curri+1)){
            left = price[curri] + solve(price,currentLength-(curri+1),curri,dp);
        }
        int right = solve(price,currentLength,curri-1,dp);
        return dp[curri][currentLength] = max(left,right);
    }
}

//TABULATION

    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        
        for(int curri=0;curri<n;curri++){
            for(int currentLength=0;currentLength<=n;currentLength++){
                if(curri == 0){
                    dp[0][currentLength] = price[0]*currentLength;
                }
                else if(currentLength == 0){
                    dp[curri][0] = 0;
                }
                else{
                    int left = 0;
                    if(currentLength >= (curri+1)){
                        left = price[curri] + dp[curri][currentLength - (curri+1)];
                    }
                    int right = dp[curri-1][currentLength];
                    dp[curri][currentLength] = max(left,right);
                    }
                }
            }
        return dp[n-1][n];
        
        return solve(price,n,n-1,dp);
    }

//SPACE OPTIMISATION

    int cutRod(int price[], int n) {
        vector<int> current(n+1,0);
        vector<int> prev(n+1,0);
        
        for(int curri=0;curri<n;curri++){
            for(int currentLength=0;currentLength<=n;currentLength++){
                if(curri == 0){
                    prev[currentLength] = price[0]*currentLength;
                }
                else if(currentLength == 0){
                    current[0] = 0;
                }
                else{
                    int left = INT_MIN;
                    if(currentLength >= (curri+1)){
                        left = price[curri] + current[currentLength - (curri+1)];
                    }
                    int right = prev[currentLength];
                    current[currentLength] = max(left,right);
                    }
                }
                prev = current;
            }
        return current[n];
    }

