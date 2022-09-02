//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            int i=0;
            int j=0;
            int n=txt.size();
            int window_size = pat.size();
            int targetHash = 0;
            for(char i:pat){
                targetHash += i;
            }
            int currentHash = 0;
            
            while(j<n){
                currentHash += txt[j];
                
                if(j-i+1 < window_size){
                    j++;
                }
                else if(j-i+1 == window_size){
                    if(currentHash==targetHash){
                        int k=0;
                        int m=i;
                        while(k<pat.size() && m<=j){
                            if(pat[k] != txt[m]){
                                break;
                            }
                            k++;
                            m++;
                        }
                        if(k==pat.size()){
                            res.push_back(i+1);
                        }
                    }
                    currentHash -= txt[i];
                    i++;
                    j++;
                }
            }
            if(!res.size()){
                res.push_back(-1);
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
