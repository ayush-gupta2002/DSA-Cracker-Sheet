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
    
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int leftDepth = depth(root -> left);
        int rightDepth = depth(root -> right);
        int ans = max(leftDepth,rightDepth) + 1;
        return ans;
    }
    
    pair<bool,int> isBalancedFaster(TreeNode* root){
        if(!root){
            pair<bool,int> res = make_pair(true,0);
            return res;
        }
        
        pair<bool,int> right = isBalancedFaster(root -> right);
        pair<bool,int> left = isBalancedFaster(root -> left);
        int heightDifference = abs(right.second - left.second);
        pair<bool,int> res;
        int depth = max(right.second,left.second) + 1;
        res.second = depth;
        if(heightDifference<=1 && right.first && left.first){
            bool resBool = true;
            res.first = true;
            return res;
        }
        res.first = false;
        return res;
        
        
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalancedFaster(root).first;
        
    }
};
