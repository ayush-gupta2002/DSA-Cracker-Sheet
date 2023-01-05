class Solution {
public:

    void makeSet(vector<int>& parent, vector<int>& rank,int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int i,vector<int>& parent){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = findParent(parent[i],parent);
    }

    void unionSet(int u,int v,vector<int>& parent,vector<int>& rank,int n){

        int uParent = findParent(u,parent);
        int vParent = findParent(v,parent);

        int uParentRank = rank[uParent];
        int vParentRank = rank[vParent];

        if(uParentRank >= vParentRank){
            parent[vParent] = uParent;
            rank[uParent]++;
        }
        else{
            parent[uParent] = vParent;
            rank[vParent]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> emailMap;
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent,rank,n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(emailMap.find(accounts[i][j]) != emailMap.end()){
                    unionSet(i,emailMap[accounts[i][j]],parent,rank,n);
                }
                else{
                    emailMap[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int,vector<string>> res;
        
        for(pair<string,int> it:emailMap){
            int parentI = findParent(it.second,parent);
            res[parentI].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(pair<int,vector<string>> it:res){
            sort(it.second.begin(),it.second.end());
            vector<string> toPush;
            toPush.push_back(accounts[it.first][0]);
            for(string str:it.second){
                toPush.push_back(str);
            }
            ans.push_back(toPush);
        }
        return ans;

    }
};
