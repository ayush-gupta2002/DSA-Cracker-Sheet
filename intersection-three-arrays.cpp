//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> answer;
            unordered_map<int,int> hash_map1;
            unordered_map<int,int> hash_map2;
            unordered_map<int,int> hash_map3;
            for(int i=0;i<n1;i++){
                hash_map1[A[i]]++;
                
            }
            for(int j=0;j<n2;j++){
                hash_map2[B[j]]++;
            }
            for(int k=0;k<n3;k++){
                hash_map3[C[k]]++;
            }
            
            for(int i=0;i<n1;i++){
                if(hash_map1[A[i]] && hash_map2[A[i]] && hash_map3[A[i]]){
                    answer.push_back(A[i]);
                    hash_map1[A[i]]=0;
                }
            }
            return answer;
            
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends
