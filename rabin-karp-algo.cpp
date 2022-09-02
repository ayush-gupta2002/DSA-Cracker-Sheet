//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        int hashingFunction(int m,char i){
            return (i-96)*((26)^(m));
        }
        
        vector <int> search(string pat, string txt)
        {
            vector<int> res;
            int i=0;
            int j=0;
            int n=txt.size();
            int window_size = pat.size();
            int m = window_size;
            int targetHash = 0;
            for(char i:pat){
                targetHash += hashingFunction(m-1,i);
                m--;
            }
            cout<<"Target hash: "<<targetHash<<endl;
            cout<<endl;
            long long int currentHash = 0;
            
            for(int j=0;j<window_size;j++){
                currentHash += hashingFunction(window_size-j-1,txt[j]);
                if(currentHash == targetHash){
                    res.push_back(i+1);
                }
                cout<<"currentHash "<<currentHash<<endl;
            }
            while(j<n){
                currentHash -= hashingFunction(window_size-1,txt[i]);
                currentHash *= 10;
                i++;
                j++;
                currentHash += hashingFunction(0,txt[j]);
                cout<<"currentHash "<<currentHash<<endl;
                
                if(currentHash == targetHash){
                    res.push_back(i+1);
                }
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
