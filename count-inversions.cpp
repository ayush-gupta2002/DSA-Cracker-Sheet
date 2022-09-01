//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    long long merge(long long arr[],long long temp[],long long left,long long right,long long mid){
        long long i=left;
        long long j=mid;
        long long k=left;
        long long count = 0;
        
        
        while(i<= mid-1 && j<=right){
            if(arr[i] <= arr[j]){
                temp[k] = arr[i];
                k++;
                i++;
            }
            else{
                temp[k] = arr[j];
                j++;
                k++;
                
                count += (mid-i);
            }
        }
        for(;j<=right;j++){
            temp[k]=arr[j];
            k++;
        }
        for(;i<=mid-1;i++){
            temp[k]=arr[i];
            k++;
        }
        for(i=left;i<=right;i++){
            arr[i] = temp[i];
        }
        return count;
    }
  
    long long mergeSort(long long arr[],long long temp[],long long left,long long right){
        long long count = 0;
        long long mid;
        if(left < right){
            mid = left + (right-left)/2;
            
            count += mergeSort(arr,temp,left,mid);
            count += mergeSort(arr,temp,mid+1,right);
            
            count += merge(arr,temp,left,right,mid+1);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long res = mergeSort(arr,temp,0,N-1);
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
