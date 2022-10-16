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
    
    int solve(TreeNode* root,int& flag,int k){
        if(!root){
            return -1;
        }
        
        int left = solve(root->left,flag,k);
        if(left != -1){
            return left;
        }
        
        flag++;
        if(flag == k){
            return root->val;
        }
        
        return solve(root->right,flag,k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int flag = 0;
        int res = solve(root,flag,k);
        return res;
    }
};
