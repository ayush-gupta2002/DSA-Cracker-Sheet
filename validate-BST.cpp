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
    
    bool isBST(TreeNode* root,int lowerLimit,int upperLimit){
        if(!root){
            return true;
        }
        
        if(root->val >= lowerLimit && root->val <= upperLimit){
            
            bool leftAns,rightAns;
            
            if(root->val == INT_MIN){
                if(root->left){
                    leftAns = false;
                }
                else{
                    leftAns = true;
                }
                rightAns = isBST(root->right,root->val+1,upperLimit);
            }
            else if(root->val == INT_MAX){
                leftAns = isBST(root->left,lowerLimit,root->val-1);
                if(root->right){
                    rightAns = false;
                }
                else{
                    rightAns = true;
                }
            }
            else{
                leftAns = isBST(root->left,lowerLimit,root->val-1);
                rightAns = isBST(root->right,root->val+1,upperLimit);
            }
            return leftAns&&rightAns;
        }
        
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        bool res = isBST(root,INT_MIN,INT_MAX);
        return res;
    }
};
