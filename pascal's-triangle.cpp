class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        res[0].push_back(1);
        if(numRows == 1){
            return res;
        }
        res[1].push_back(1);
        res[1].push_back(1);
        if(numRows == 2){
            return res;
        }

        for(int i=2;i<numRows;i++){
            vector<int> vec(i+1);
            vec[0] = 1;
            vec[vec.size()-1] = 1;
            int a=0;
            int b=1;
            for(int k=1;k<vec.size()-1;k++){
                vec[k] = res[i-1][a] + res[i-1][b];
                a++;
                b++;
            }
            res[i] = vec;
        }
        return res;

    }
};
