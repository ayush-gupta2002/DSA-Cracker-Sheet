/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int findPosition(int element,vector<int> inorder,map<int,int>& nodeToIndex){
        return nodeToIndex[element];
        
    }
    
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int& postorderIndex,int inorderStartingIndex,int inorderEndingIndex,map<int,int>& nodeToIndex){
        if(postorderIndex < 0){
            return NULL;
        }
        if(inorderStartingIndex > inorderEndingIndex){
            return NULL;
        }
        
        int element = postorder[postorderIndex--];
        TreeNode* temp = new TreeNode(element);
        int inorderPosition = findPosition(element,inorder,nodeToIndex);
        temp->right = solve(inorder,postorder,postorderIndex,inorderPosition+1,inorderEndingIndex,nodeToIndex);
        temp -> left = solve(inorder,postorder,postorderIndex,inorderStartingIndex,inorderPosition -1,nodeToIndex);
        
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderIndex = n-1;
        map<int,int> nodeToIndex;
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]] = i;
        }
        TreeNode* res = solve(inorder,postorder,postorderIndex,0,n-1,nodeToIndex);
        return res;
    }
};
