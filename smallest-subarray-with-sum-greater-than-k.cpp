//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int i=0;
        int j=0;
        int min_length = n;
        int total = 0;
        
        while(j<n){
            total += arr[j];
            
            if(total > x){
                min_length = min(min_length,(j-i+1));
                while((total - arr[i])>x){
                    total -= arr[i];
                    i++;
                    min_length = min(min_length,(j-i+1));
                }
                j++;
            }
            else if(total < x){
                j++;
            }
            else {
                j++;
            }
        }
        return min_length;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends
