class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int count = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int total = r*c;
        
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = r-1;
        int endingCol = c-1;
        
        while(count < total){
            for(int index = startingCol;count < total && index<=endingCol;index++){
                res.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            for(int index = startingRow;count < total && index<=endingRow;index++){
                res.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            for(int index = endingCol;count < total && index>=startingCol;index--){
                res.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            for(int index = endingRow;count < total && index>=startingRow;index--){
                res.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return res;
    }
};
