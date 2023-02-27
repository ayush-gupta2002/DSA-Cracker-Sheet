//MEMOIZATION

    int solve(string& word1,string& word2,int ind1,int ind2,vector<vector<int>>& dp){

        if(ind2<0){
            return ind1+1;
        }
        else if(ind1<0){
            return ind2+1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int ans1 = 1e9;
        int ans2 = 1e9;
        int ans3 = 1e9;
        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2] = solve(word1,word2,ind1-1,ind2-1,dp);
        }
        else{
            //DELETE
            ans1 = 1 + solve(word1,word2,ind1-1,ind2,dp);
            //REPLACE
            ans2 = 1 + solve(word1,word2,ind1-1,ind2-1,dp);
            //INSERT
            ans3 = 1 + solve(word1,word2,ind1,ind2-1,dp);

            return dp[ind1][ind2] = min({ans3,ans1,ans2});
        }
    }

//TABULATION

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int ind1 = 0;ind1<=n;ind1++){
            dp[ind1][0] = ind1;
        }

        for(int ind2=1;ind2<=m;ind2++){
            dp[0][ind2] = ind2;
        }

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = min({(1 + dp[ind1-1][ind2]), (1 + dp[ind1-1][ind2-1]), (1 + dp[ind1][ind2-1])});
                }
            }
        }

        return dp[n][m];
    }

//SPACE OPTIMISED

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> curr(m+1,0),prev(m+1,0);
        for(int i=0;i<=m;i++){
            prev[i] = i;
        }
        for(int ind1=1;ind1<=n;ind1++){
            curr[0] = ind1;
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    curr[ind2] = prev[ind2-1];
                }
                else{
                    curr[ind2] = min({(1 + prev[ind2]), (1 + prev[ind2-1]), (1 + curr[ind2-1])});
                }
            }
            prev = curr;
        }

        return prev[m];
    }
