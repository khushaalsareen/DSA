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
    int findSum(TreeNode * root, int &ans){
        if(!root)
        return 0;

        int sumLeft = findSum(root->left,ans);
        int sumRight = findSum(root->right,ans);
        int currSum = root->val +  max({sumLeft,sumRight,sumLeft + sumRight,0});
        ans = max(ans,currSum);

        return root->val + max({sumLeft,sumRight,0});
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
        return 0;
        int ans = -1e9;
         findSum(root,ans);
         return ans;
    }
};