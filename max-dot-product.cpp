//MEMOIZATION

    int solve(vector<int>& nums1,vector<int>& nums2,int ind1,int ind2,vector<vector<int>>& dp){
        if(ind1 == nums1.size() || ind2 == nums2.size()){
            return -1e9;
        }



        if(dp[ind1][ind2] != -1e9){
            return dp[ind1][ind2];
        }
        int ans1 = nums1[ind1]*nums2[ind2];
        int ans2 = ans1;
        int ans3 = ans2;
        int ans4 = ans3;
        int ans5 = ans1;

        if(ind1 < nums1.size()-1 && ind2 < nums2.size()-1){
            ans1 = (nums1[ind1]*nums2[ind2]) + solve(nums1,nums2,ind1+1,ind2+1,dp);
            ans4 = solve(nums1,nums2,ind1+1,ind2+1,dp);
        }
        if(ind1 < nums1.size()-1){
            ans2 = solve(nums1,nums2,ind1+1,ind2,dp);
        }
        if(ind2 < nums2.size()-1){
            ans3 = solve(nums1,nums2,ind1,ind2+1,dp);
        }

        // cout<<ind1<<" "<<ind2<<" "<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;

        return dp[ind1][ind2] = max({ans1,ans2,ans3,ans4,ans5});
    }


//TABULATION

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp (n+1, vector<int> (m+1,-1e9));

        for(int ind1 = n-1;ind1>=0;ind1--){
            for(int ind2 = m-1;ind2>=0;ind2--){
                int ans1 = nums1[ind1]*nums2[ind2];
                int ans2 = ans1;
                int ans3 = ans1;
                int ans4 = ans1;
                int ans5 = ans1;

                if(ind1 < nums1.size()-1 && ind2 < nums2.size()-1){
                    ans1 = (nums1[ind1]*nums2[ind2]) + dp[ind1+1][ind2+1];
                    ans4 = dp[ind1+1][ind2+1];
                }
                if(ind1 < nums1.size()-1){
                    ans2 = dp[ind1+1][ind2];
                }
                if(ind2 < nums2.size()-1){
                    ans3 = dp[ind1][ind2+1];
                }

                dp[ind1][ind2] = max({ans1,ans2,ans3,ans4,ans5});
            }
        }
        return dp[0][0];
    }

//SPACE OPTIMISATION

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> curr(m+1,-1e9), next(m+1,-1e9);

        for(int ind1 = n-1;ind1>=0;ind1--){
            for(int ind2 = m-1;ind2>=0;ind2--){
                int ans1 = nums1[ind1]*nums2[ind2];
                int ans2 = ans1;
                int ans3 = ans1;
                int ans4 = ans1;
                int ans5 = ans1;

                if(ind1 < nums1.size()-1 && ind2 < nums2.size()-1){
                    ans1 = (nums1[ind1]*nums2[ind2]) + next[ind2+1];
                    ans4 = next[ind2+1];
                }
                if(ind1 < nums1.size()-1){
                    ans2 = next[ind2];
                }
                if(ind2 < nums2.size()-1){
                    ans3 = curr[ind2+1];
                }

                curr[ind2] = max({ans1,ans2,ans3,ans4,ans5});
            }
            next = curr;
        }
        return curr[0];
    }
