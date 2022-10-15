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
    
    TreeNode* find(TreeNode* root){
        TreeNode* current = root;
        current = current -> left;
        
        while(current->right){
            current = current -> right;
        }
        return current;
    }
    
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        
        while(current){
            if(current -> left){
                TreeNode* predecessor = find(current);
                predecessor -> right = current -> right;
                current -> right = current -> left;
                current -> left = NULL;
            }
            current = current -> right;
        }
    }
};
