class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //length of shortest common supersequence = n + m - lcs

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int ind1 = 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(str1[ind1-1] == str2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }

        int ind1 = n;
        int ind2 = m;
        string res;

        // for(int ind1=0;ind1<=n;ind1++){
        //     for(int ind2=0;ind2<=m;ind2++){
        //         cout<<dp[ind1][ind2]<<" ";
        //     }cout<<endl;
        // }

        while(ind1 > 0 && ind2 > 0){
            if(str1[ind1-1] == str2[ind2-1]){
                res.push_back(str1[ind1-1]);
                ind1--;
                ind2--;

            }else{
                if(dp[ind1-1][ind2] >= dp[ind1][ind2-1]){
                    res.push_back(str1[ind1-1]);
                    ind1--;
                }
                else{
                    res.push_back(str2[ind2-1]);
                    ind2--;
                }
            }
        }

        // for(int ind1 = 0;ind1<=n;ind1++){
        //     for(int ind2=0;ind2<=m;ind2++){
        //         cout<<dp[ind1][ind2]<<" ";
        //     }cout<<endl;
        // }

        while(ind1 > 0){
            res.push_back(str1[ind1-1]);
            ind1--;
        }
        while(ind2 > 0){
            res.push_back(str2[ind2-1]);
            ind2--;
        }
        reverse(res.begin(),res.end());
        cout<<ind1<<" "<<ind2<<endl;
        return res;

    }
};
