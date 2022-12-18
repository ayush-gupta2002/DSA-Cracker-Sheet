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
        }
        insertUtil(word.substr(1),child);
    }
    
    void insert(string word) {
        insertUtil(word,root);
    }

    bool searchUtil(string word,TrieNode* root){
        if(word.length() == 0){
            if(root -> isTerminal == true){
                return true;
            }
            return false;
        }

        int index = word[0] - 'a';
        if(root -> children[index]){
            return searchUtil(word.substr(1),root->children[index]);
        }
        else{
            return false;
        }
    }
    
    bool search(string word) {
        return searchUtil(word,root);
    }

    bool startsWithUtil(string prefix,TrieNode* root){
        if(prefix.length() == 0){
            return true;
        }

        int index = prefix[0] - 'a';
        if(root -> children[index]){
            return startsWithUtil(prefix.substr(1),root->children[index]);
        }
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(prefix,root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
