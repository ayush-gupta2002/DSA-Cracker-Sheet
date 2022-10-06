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
    
    void solve(int level,TreeNode* root,vector<int> &res){
        if(!root){
            return;
        }
        
        if(res.size() == level){
            res.push_back(root->val);
        }
        
        solve(level+1,root->right,res);
        solve(level+1,root->left,res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(0,root,res);
        return res;
    }
};
