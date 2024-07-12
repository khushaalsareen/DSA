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
    int height(TreeNode*root, int &ans){
        if(!root)
        return 0;
        int lh = height(root->left,ans);
        int rh = height(root->right,ans);
        lh = max(lh,0);
        rh = max(rh,0);
        ans = max(ans,root->val + lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
        return 0;
        int ans = -1e9;
        height(root,ans);
        return ans;
    }
};