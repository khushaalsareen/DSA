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
    int f(TreeNode*root, int &ans){
        if(!root)
        return 0;

        int lsum = f(root->left,ans);
        int rsum = f(root->right,ans);
        int currAns = root->val + max({lsum,rsum,lsum+rsum,0});
        ans = max(ans,currAns);

        return root->val + max({lsum,rsum,0});
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
        return 0;
        int ans = -1e9;
         f(root,ans);
         return ans;
    }
};