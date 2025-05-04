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
    int ans = -1e9;
    int maxSum(TreeNode*root){
        if(!root)
        return 0;

        int ls = maxSum(root->left);
        int rs = maxSum(root->right);
        ans = max(ans,root->val + max(ls,0) + max(rs,0));
        return root->val + max({ls,rs,0});
    }
public:
    int maxPathSum(TreeNode* root) {
         maxSum(root); // max sum path passing through root
         return ans;    // max sum path that takes a turn about any node n in tree is final ans
    }
};