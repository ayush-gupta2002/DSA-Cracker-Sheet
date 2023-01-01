class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        words.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            pair<string,int> frontPair = q.front();
            q.pop();
            string topWord = frontPair.first;
            int currentLevel = frontPair.second;
            if(topWord == endWord){
                return currentLevel;
            }
            for(int i=0;i<topWord.size();i++){
                char original = topWord[i];
                for(char j = 'a';j<='z';j++){
                    topWord[i] = j;
                    if(words.find(topWord) != words.end()){
                        q.push({topWord,currentLevel+1});
                        words.erase(topWord);
                    }
                }
                topWord[i] = original;
            }
        }
        return 0;
    }
};
