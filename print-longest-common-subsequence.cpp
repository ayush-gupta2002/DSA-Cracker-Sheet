int lcs(string text1, string text2)
{
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
        int ind1 = n1;
        int ind2 = n2;
        string res;

        while(ind1 != 0 && ind2 != 0){
            cout<<ind1<<" "<<ind2<<endl;
            if(text1[ind1-1] == text2[ind2-1]){
                res.push_back(text1[ind1-1]);
                ind1 -= 1;
                ind2 -= 1;
            }
            else{
                if(dp[ind1-1][ind2] >= dp[ind1][ind2-1]){
                    ind1 -= 1;
                }else{
                    ind2 -= 1;
                }
            }
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;

        return dp[n1][n2];
}
