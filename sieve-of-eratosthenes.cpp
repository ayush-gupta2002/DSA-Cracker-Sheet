//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int> sieve(n+1,0);
        
        for(int i=2;i*i<n;i++){
            if(!sieve[i]){
                for(int p=i*i;p<=n;p+=i){
                    sieve[p] = 1;
                }
            }
        }
        
        vector<int> res;
        
        for(int i=2;i<=n;i++){
            if(!sieve[i]){
                res.push_back(i);
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
