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
    
    int findPosition(vector<int>& inorder,int element,map<int,int>& nodeToIndex){
        
        return nodeToIndex[element];
    }
    
    TreeNode* solve(vector<int>& preorder,vector<int>&inorder,int &preOrderIndex,int inOrderStartingIndex,int inOrderEndingIndex,map<int,int>& nodeToIndex){
        if(preOrderIndex >= preorder.size()){
            return NULL;
        }
        if(inOrderStartingIndex > inOrderEndingIndex){
            return NULL;
        }
        
        int element = preorder[preOrderIndex++];
        TreeNode* temp = new TreeNode(element);
        int position = findPosition(inorder,element,nodeToIndex);
        
        temp -> left = solve(preorder,inorder,preOrderIndex,inOrderStartingIndex,position-1,nodeToIndex);
        temp -> right = solve(preorder,inorder,preOrderIndex,position+1,inOrderEndingIndex,nodeToIndex);
        
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> nodeToIndex;
        for(int i=0;i<inorder.size();i++){
            nodeToIndex[inorder[i]] = i;
        }
        
        int preOrderIndex = 0;
        int inOrderSize = inorder.size();
        TreeNode* res = solve(preorder,inorder,preOrderIndex,0,inOrderSize-1,nodeToIndex);
        return res;
        
    }
};
