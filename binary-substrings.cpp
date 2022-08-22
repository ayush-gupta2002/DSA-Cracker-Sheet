//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int currentZeroes = 0;
        int currentOnes = 0;
        int res=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                currentZeroes++;
            }
            else{
                currentOnes++;
            }
            if(currentZeroes == currentOnes){
                res++;
            }
        }
        if(currentZeroes!=currentOnes){
            return -1;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
