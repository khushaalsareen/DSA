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
    int findSum(TreeNode*root, int &maxSum){
        if(!root)
        return 0;

        int left = findSum(root->left,maxSum);
        int right = findSum(root->right,maxSum);
        int currSum = root->val + max({left,right,left+right,0});
        maxSum = max(maxSum,currSum);
        return root->val + max({left, right, 0});
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = -1e9;
        findSum(root,maxSum);
        return maxSum;
    }
};