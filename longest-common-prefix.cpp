class Solution {
public:

    class TrieNode{
        public:
            char data;
            TrieNode* children[26];
            bool isTerminal;
            int childCount;

            TrieNode(char ch){
                data = ch;
                isTerminal = false;
                childCount = 0;
                for(int i=0;i<26;i++){
                    children[i] = NULL;
                }
            }
    }; 

    class Trie{
        public:
            TrieNode* root = NULL;

            Trie() {
                root = new TrieNode('\0');
            }

            void insertUtil(string word,TrieNode* root){
                if(word.length() == 0){
                    root -> isTerminal = true;
                    return;
                }

                TrieNode* child = NULL;
                int index = word[0] - 'a';

                if(root -> children[index]){
                    child = root -> children[index];
                }
                else{
                    child = new TrieNode(word[0]);
                    root -> children[index] = child;
                    root -> childCount++;
                }
                insertUtil(word.substr(1),child);
            }
            
            void insert(string word){
                insertUtil(word,root);
            }
            
            void lcp(string str,string &ans){
                for(int i=0;i<str.length();i++){
                    char ch = str[i];
                    if(root -> childCount == 1){
                        ans.push_back(ch);
                        int index = ch - 'a';
                        root = root -> children[index];
                    }
                    else{
                        break;
                    }

                    if(root -> isTerminal){
                        break;
                    }
                }
            }

    };

    string longestCommonPrefix(vector<string>& strs) {

        Trie* t = new Trie();
        for(string i:strs){
            if(i.length() == 0){
                return "";
            }
            t -> insert(i);
        }
        string first = strs[0];
        string res = "";
        t -> lcp(first,res);
        return res;

    }
};
