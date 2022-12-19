//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root,string word){
            if(word.length() == 0){
                root -> isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root -> children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode* root,string word){
            if(word.length() == 0){
                if(root -> isTerminal){
                    return true;
                }
                return false;
            }

            int index = word[0] - 'a';
            TrieNode* child;
            if(root -> children[index]){
                child = root -> children[index];
                return searchUtil(child,word.substr(1));
            }
            else{
                return false;
            }

        }

        bool searchWord(string word){
            return searchUtil(root,word);
        }

    bool wordBreakUtil(string const &s,TrieNode* root){
        int size = s.length();

        if(size == 0){
            return true;
        }

        for(int i=1;i<=size;i++){
            if(searchWord(s.substr(0,i)) && wordBreakUtil(s.substr(i,size-1),root)){
                return true;
            }
        }
        return false;
    }

    bool wordBreak2(string s){
        return wordBreakUtil(s,root);
    }

    };
    
    int wordBreak(string A, vector<string> &B) {
        Trie *t = new Trie();
        for(string str:B){
            t -> insertWord(str);
        }
        return t->wordBreak2(A);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
