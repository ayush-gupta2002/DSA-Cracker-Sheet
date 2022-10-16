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
    
    void inorder(TreeNode* root,vector<int>& res){
        if(!root){
            return;
        }
        
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    
    TreeNode* balanced(vector<int> &inorder,int startingIndex,int endingIndex){
        
        if(startingIndex > endingIndex){
            return NULL;
        }
        
        int mid = (startingIndex + endingIndex)/2;
        
        TreeNode* temp = new TreeNode(inorder[mid]);
        temp->left = balanced(inorder,startingIndex,mid-1);
        temp->right = balanced(inorder,mid+1,endingIndex);
        
        return temp;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        
        TreeNode* ans = balanced(res,0,res.size()-1);
        return ans;
        
    }
};
