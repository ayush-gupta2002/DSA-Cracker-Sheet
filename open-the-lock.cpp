class Solution {
public:

    vector<string> neighbors(string str,int i){
        vector<string> res(2,str);

        res[1][i] = '0' + (res[1][i] - '0' + 1)%10;
        res[0][i] = '0' + (res[0][i] - '0' - 1 + 10)%10;

        return res;
    }

    int openLock(vector<string>& deadends, string target) {

        if(target == "0000"){
            return 0;
        }

        unordered_map<string,bool> visited;
        for(string it:deadends){
            visited[it] = 1;
        }

        if(visited["0000"]){
            return -1;
        }

        queue<pair<string,int>> q;
        q.push({"0000",1});

        while(!q.empty()){
            pair<string,int> frontPair = q.front();
            q.pop();

            string frontStr = frontPair.first;

            int moves = frontPair.second;            
            for(int i=0;i<4;i++){
                for(string temp:neighbors(frontStr,i)){
                    if(!visited[temp]){
                        if(temp == target){
                            return moves;
                        }
                        visited[temp] = 1;
                        q.push({temp,moves+1});
                    }
                }
            }
        }
        return -1;
    }
};
