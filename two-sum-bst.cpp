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
    
    void inorder(vector<int>& res,TreeNode* root){
        if(!root){
            return;
        }
        
        inorder(res,root->left);
        res.push_back(root->val);
        inorder(res,root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(res,root);
        
        int i=0;
        int j=res.size()-1;
        while(i<j){
            if(res[i]+res[j] == k){
                return true;
            }
            else if(res[i]+res[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};
