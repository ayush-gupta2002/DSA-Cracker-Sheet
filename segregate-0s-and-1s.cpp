//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        int l = 0;
        int r = n-1;
        
        while(l<r){
            
            //l correct r incorrect
            if(arr[l] == 0 && arr[r] == 0){
                l++;
            }
            
            //l correct r correct
            else if(arr[l] == 0 && arr[r] == 1){
                l++;
                r--;
            }
            
            //l incorrect r correct
            else if(arr[l] == 1 && arr[r] == 1){
                r--;
            }
            
            //l incorrect r incorrect
            else{
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
