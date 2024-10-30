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
    int f(TreeNode*root,unordered_map<TreeNode*, int>&m){
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return root->val;
        
        if(m.find(root)!=m.end())
        return m[root];

        int take = 0;
        if(root->left)
         take += f(root->left->left,m) + f(root->left->right,m);
        if(root->right)
         take+= f(root->right->left,m) + f(root->right->right,m);
        take += root->val;

        int notTake = f(root->left,m)+f(root->right,m);
        return m[root] = max(take,notTake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>m;
        return f(root,m);
    }
};