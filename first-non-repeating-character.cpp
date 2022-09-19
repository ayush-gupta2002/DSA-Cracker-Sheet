//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int> frequency;
		    string res = "";
		    queue<char> q;
		    int i = 0;
		    int n = A.length();
		    while(i < n){
		        frequency[A[i]]++;
		        q.push(A[i]);
		        while(!q.empty()){
		            if(frequency[q.front()]>1){
		                q.pop();
		            }
		            else{
		                res.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            res.push_back('#');
		        }
		        i++;
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
