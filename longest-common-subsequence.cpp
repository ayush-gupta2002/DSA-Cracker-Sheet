//MEMOIZATION

    int solve(string& text1, string& text2,int ind1,int ind2,vector<vector<int>>& dp){

        if(ind1<0 || ind2<0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        if(text1[ind1] == text2[ind2]){
            ans1 = 1 + solve(text1,text2,ind1-1,ind2-1,dp);
        }
        else{
            ans2 = solve(text1,text2,ind1-1,ind2,dp);
            ans3 = solve(text1,text2,ind1,ind2-1,dp);
        }
        return dp[ind1][ind2] = max(ans1,max(ans2,ans3));

    }

//TABULATION

   int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        for(int ind1=0;ind1<=n1;ind1++){
            dp[ind1][0] = 0;
        }
        for(int ind2=0;ind2<=n2;ind2++){
            dp[0][ind2] = 0;
        }

        for(int ind1 = 1;ind1 <= n1;ind1++){
            for(int ind2=1;ind2 <= n2;ind2++){
                int ans1 = 0;
                int ans2 = 0;
                int ans3 = 0;
                if(text1[ind1-1] == text2[ind2-1]){
                    ans1 = 1 + dp[ind1-1][ind2-1];
                }
                else{
                        ans1 = dp[ind1-1][ind2];
                        ans2 = dp[ind1][ind2-1];
                }
                dp[ind1][ind2] = max({ans1,ans2,ans3});
            }
        }
        return dp[n1][n2];
    }

//SPACE OPTIMISATION

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);

        for(int ind2=0;ind2<=n2;ind2++){
            curr[ind2] = 0;
        }

        for(int ind1 = 1;ind1 <= n1;ind1++){
            for(int ind2=1;ind2 <= n2;ind2++){
                int ans1 = 0;
                int ans2 = 0;
                int ans3 = 0;
                if(text1[ind1-1] == text2[ind2-1]){
                    ans1 = 1 + prev[ind2-1];
                }
                else{
                        ans1 = prev[ind2];
                        ans2 = curr[ind2-1];
                }
                curr[ind2] = max({ans1,ans2,ans3});
            }
            prev = curr;
        }
        return curr[n2];
    }
