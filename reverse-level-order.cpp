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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> elements;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        q.push(NULL);
        
        if(!root){
            return res;
        }
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            s.push(temp);
            
            if(!temp){
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->right){
                    q.push(temp -> right);
                }
                if(temp -> left){
                    q.push(temp -> left);
                }
            }
        }
        while(!s.empty()){
            TreeNode* root = s.top();
            s.pop();
            if(!root && elements.size()>0){
                res.push_back(elements);
                elements.clear();
            }
            else if(root){
                elements.push_back(root -> val);
            }
            if(root){
                cout<< root->val <<" ";
            }
            else{
                cout<<endl;
            }
        }
        res.push_back(elements);
        return res;
    }
};
