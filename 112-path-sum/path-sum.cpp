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
    bool isSum(TreeNode*root, int target, int &ans){
        if(!root)
        return false;
        if(!root->left && !root->right)
        return ans == root->val;
        
        ans = ans-root->val;
        bool b1 = isSum(root->left,target,ans);
        bool b2 = isSum(root->right,target,ans);
        ans = ans+root->val;
        return b1|| b2;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root ) return false;
        int ans = targetSum;
        return isSum(root,targetSum,ans);
    }
};