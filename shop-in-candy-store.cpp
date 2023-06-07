//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        int bag = 0;
        
        vector<int> candy;
        for(int i=0;i<N;i++){
            candy.push_back(candies[i]);
        }
        sort(candy.begin(),candy.end());
        int spent = 0;
        int i = 0;
        
        while(bag < N){
            spent += candy[i];
            bag += K+1;
            i++;
        }
        
        int minAns = spent;
        
        spent = 0;
        
        bag = 0;
        spent = 0;
        i = N-1;
        
        while(bag < N){
            spent += candy[i];
            bag += K+1;
            i--;
        }
        
        int maxAns = spent;
        
        return {minAns,maxAns};
        

        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
