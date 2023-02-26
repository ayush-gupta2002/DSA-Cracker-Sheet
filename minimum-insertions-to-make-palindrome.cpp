//MEMOIZATION

    int lcs(string& s1,string& s2,int ind1,int ind2,vector<vector<int>>& dp){
        if(ind1 < 0 || ind2<0){
            return 0;
        }

        if(s1[ind1] == s2[ind2]){
            return 1 + lcs(s1,s2,ind1-1,ind2-1,dp);
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int ans1 = 0;
        int ans2 = 0;

        if(ind1>0){
            ans1 = lcs(s1,s2,ind1-1,ind2,dp);
        }
        if(ind2>0){
            ans2 = lcs(s1,s2,ind1,ind2-1,dp);
        }

        return dp[ind1][ind2] = max(ans1,ans2);
    }

//TABULATION

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }

        int LCS = dp[n][n];

        return n - LCS;
    }

//TABULATION WITH SPACE OPTIMISATION

    int minInsertions(string s) {
        int n = s.size();
        vector<int> curr(n+1),prev(n+1);
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    curr[ind2] = 1 + prev[ind2-1];
                }
                else{
                    curr[ind2] =max(prev[ind2],curr[ind2-1]);
                }
            }
            prev = curr;
        }

        int LCS = curr[n];

        return n - LCS;
    }
