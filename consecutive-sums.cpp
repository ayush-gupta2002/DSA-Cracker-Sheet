//SLIDING WINDOW APPROACH

#include <bits/stdc++.h> 
using namespace std;

int countWays(int n)
{
        int i=1;
        int j=1;
        int res = 0;

        int currentSum = 1;

        while(j<=((n/2)+1)){
            // cout<<i<<" "<<j<<" "<<currentSum<<endl;
            if(currentSum == n && !(j>=n)){
                res++;
                currentSum -= i;
                i++;
                j++;
                currentSum += j;
            }
            else if(currentSum > n){
                while(currentSum > n){
                    currentSum -= i;
                    i++;
                }
            }
            else{
                j++;
                currentSum += j;
            }
        }
        return res;
}

//MATHEMATICAL APPROACH

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int getCount(int n) {
        int k = 2;
        int res = 0;
        while(k*(k-1) < 2*n){
            if((n- (k*(k-1)/2))%k == 0){
                res++;
            }
            k++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.getCount(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
