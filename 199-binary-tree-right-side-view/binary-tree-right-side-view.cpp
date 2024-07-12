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
    void levelOrder(TreeNode*root,vector<int>&ans){
        if(!root)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            bool flag = false;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode * node = q.front();
                q.pop();
                if(flag == false)
                {ans.push_back(node->val);
                flag = true;
                }
                if(node->right)
                q.push(node->right);
                if(node->left)
                q.push(node->left);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        levelOrder(root,ans);
        return ans;
    }
};