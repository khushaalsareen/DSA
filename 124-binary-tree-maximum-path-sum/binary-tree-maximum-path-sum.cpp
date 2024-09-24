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
    int findSum(TreeNode*root, int &ans){
        if(!root)
        return 0;

        int lh = findSum(root->left,ans);
        int rh = findSum(root->right,ans);
        lh = max(lh,0);
        rh = max(rh,0);
        ans = max({ans,root->val,root->val+lh,root->val+rh,root->val+lh+rh});
        return root->val + max({lh,rh,0});
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
         findSum(root,ans);
         return ans;
    }
};