//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 vector<long long> answer;
                                                 deque<long long> negative_integers;
                                                 
                                                 for(int i=0;i<K;i++){
                                                     if(A[i]<0){
                                                         negative_integers.push_back(A[i]);
                                                     }
                                                 }
                                                 if(negative_integers.size()!=0){
                                                     answer.push_back(negative_integers.front());
                                                 }
                                                 else{
                                                     answer.push_back(0);
                                                 }
                                                 int j=0;
                                                 for(int i=K;i<N;i++){
                                                     if(A[j]==negative_integers.front()){
                                                         negative_integers.pop_front();
                                                     }
                                                     j++;
                                                     if(A[i]<0){
                                                         negative_integers.push_back(A[i]);
                                                     }
                                                     if(negative_integers.size() != 0){
                                                         answer.push_back(negative_integers.front());
                                                     }
                                                     else if(negative_integers.size() == 0){
                                                         answer.push_back(0);
                                                     }
                                                 }
                                                 return answer;
 }
