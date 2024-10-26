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
    void levelOrder(TreeNode*root,vector<vector<int>>&ans ){
        queue<TreeNode*>q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            level++;
            int sz = q.size();
            vector<int>v(sz);
            int idx = level%2 == 0 ? 0 : sz-1;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                v[idx] = node->val;
                if(level%2 == 0)
                idx++;
                else
                idx--;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
        return ans;
        levelOrder(root,ans);
        return ans;
    }
};