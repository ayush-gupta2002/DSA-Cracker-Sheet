class Solution {
public:

    int solve(string&s, string& p,int ind1,int ind2,vector<vector<int>>& dp){
        if(ind1<0 && ind2<0){

            return 1;
        }
        else if(ind1<0 && p[ind2] == '*'){
            return solve(s,p,ind1,ind2-1,dp);
        }
        else if(ind1<0 && ind2>=0){

            return 0;
        }
        else if(ind1>=0 && ind2<0){

            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == p[ind2] || p[ind2] == '?'){

            return dp[ind1][ind2] = solve(s,p,ind1-1,ind2-1,dp);

        }else{
            if(s[ind1] != p[ind2] && p[ind2] != '*'){

                return dp[ind1][ind2] = 0;
            }
            else if(s[ind1] != p[ind2] && p[ind2] == '*'){
                bool ans1 = solve(s,p,ind1-1,ind2,dp);
                bool ans2 = solve(s,p,ind1,ind2-1,dp);
                return dp[ind1][ind2] = ans1||ans2;
            }
        }
        return dp[ind1][ind2] = 1;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        bool ans = solve(s,p,n-1,m-1,dp);
        return ans;
    }
};
