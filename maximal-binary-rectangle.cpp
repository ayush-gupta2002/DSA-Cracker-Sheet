class Solution {
public:
    
    vector<int> previousSmallerElement(vector<int> heights){
        vector<int> res;
        stack<int> myStack;
        myStack.push(-1);
        for(int i=0;i<heights.size();i++){
            while(myStack.top() != -1 && heights[myStack.top()] >= heights[i]){
                myStack.pop();
            }
            res.push_back(myStack.top());
            myStack.push(i);
        }
        return res;
    }
    
    vector<int> nextSmallerElement(vector<int> heights){
        vector<int> res;
        stack<int> myStack;
        myStack.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(myStack.top() != -1 && heights[myStack.top()] >= heights[i]){
                myStack.pop();
            }
            res.push_back(myStack.top());
            myStack.push(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftSmaller = previousSmallerElement(heights);
        vector<int> rightSmaller = nextSmallerElement(heights);
        int maxArea = 0;
        for(int i=0;i<heights.size();i++){
            int width = rightSmaller[i] - leftSmaller[i]-1;
            if(rightSmaller[i] == -1){
                width = heights.size() - leftSmaller[i] - 1;
            }
            int currentArea = width * heights[i];
            maxArea = max(currentArea,maxArea);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> M(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                M[i].push_back(matrix[i][j]-48);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<M[i][j]<<" ";
            }cout<<endl;
        }
        
        int maxArea = largestRectangleArea(M[0]);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0){
                    M[i][j] = (M[i][j]) + (M[i-1][j]);
                }
            }
            maxArea = max(maxArea,largestRectangleArea(M[i]));
        }
        return maxArea;
    }
};
