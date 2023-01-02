//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<string> l = {beginWord};
        q.push(l);
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> res;
        
        while(!q.empty()){
            vector<string> frontList = q.front();
            q.pop();
            if(frontList.size() > level){
                level++;
                for(string it:usedOnLevel){
                    words.erase(it);
                }
            }
            string frontWord = frontList[frontList.size() - 1];
            if(frontWord == endWord){
                res.push_back(frontList);
            }
            for(int i=0;i<frontWord.size();i++){
                char original = frontWord[i];
                for(char ch = 'a';ch<='z';ch++){
                    frontWord[i] = ch;
                    if(words.find(frontWord) != words.end()){
                        frontList.push_back(frontWord);
                        q.push(frontList);
                        usedOnLevel.push_back(frontWord);
                        frontList.pop_back();
                    }
                }
                frontWord[i] = original;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
