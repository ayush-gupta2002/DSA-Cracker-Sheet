//MEMOIZATION

    int solve(string& s,string& t,int ind1,int ind2,vector<vector<int>>& dp){

        if(ind2<0){
            return 1;
        }
        else if(ind1<0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = solve(s,t,ind1-1,ind2-1,dp) + solve(s,t,ind1-1,ind2,dp);
        }
        else{
            return dp[ind1][ind2] = solve(s,t,ind1-1,ind2,dp);
        }
    }

//TABULATION
   int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long int>> dp(n+1,vector<unsigned long long int> (m+1,0));

        for(int ind1=0;ind1<=n;ind1++){
            dp[ind1][0] = 1;
        }

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1] == t[ind2-1]){
                    dp[ind1][ind2] = dp[ind1-1][ind2-1] + dp[ind1-1][ind2];
                }
                else{
                    dp[ind1][ind2] = dp[ind1-1][ind2];
                }
            }
        }

        return dp[n][m];
    }

//TABULATION WITH SPACE OPTIMISATION

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long int> prev(m+1,0),curr(m+1,0);

        curr[0] = 1;
        prev[0] = 1;

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1] == t[ind2-1]){
                    curr[ind2] = prev[ind2-1] + prev[ind2];
                }
                else{
                    curr[ind2] = prev[ind2];
                }
            }
            prev = curr;
        }

        return curr[m];
    }
