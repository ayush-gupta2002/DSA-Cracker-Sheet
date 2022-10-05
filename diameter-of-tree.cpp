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
    
    int depthOfBinaryTree(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int leftHeight = depthOfBinaryTree(root -> left);
        int rightHeight = depthOfBinaryTree(root -> right);
        return (max(leftHeight,rightHeight) + 1);
    }
    
    pair<int,int> diameterFast(TreeNode* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root -> left);
        pair<int,int> right = diameterFast(root -> right);
        
        int leftDiameter = left.first;
        int rightDiameter = right.first;
        int leftHeight = left.second;
        int rightHeight = right.second;
        int mixDiameter = leftHeight + rightHeight +1;
        
        int resDiameter = max({mixDiameter,leftDiameter,rightDiameter});
        int resHeight = max({leftHeight,rightHeight}) + 1;
        pair<int,int> res = make_pair(resDiameter,resHeight);
        return res;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
         pair<int,int> res = diameterFast(root);
         return res.first - 1;
        
    }
};
