
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

        
        void printSuggestions(TrieNode* current,vector<string>& temp, string prefix){
            if(current -> isTerminal){
                temp.push_back(prefix);
            }
            
            for(char ch = 'a'; ch<='z';ch++){
                TrieNode* next = current -> children[ch - 'a'];
                
                if(next){
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        
        vector<vector<string>> getSuggestions(string s){
            TrieNode* prev = root;
            vector<vector<string>> res;
            string prefix = "";
            
            for(int i=0;i<s.length();i++){
                char lastChar = s[i];
                prefix.push_back(lastChar);
                
                int index = lastChar - 'a';
                
                TrieNode* curr = prev -> children[index];
                
                if(curr == NULL){
                    break;
                }
                else{
                    vector<string> temp;
                    printSuggestions(curr,temp,prefix);
                    res.push_back(temp);
                    temp.clear();
                    prev = curr;
                }
            }
            return res;
        }
    };

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie();
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t -> insertWord(str);
    }
    
    return t -> getSuggestions(queryStr);
}
