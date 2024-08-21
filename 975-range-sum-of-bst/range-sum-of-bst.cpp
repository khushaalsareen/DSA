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
    void search(TreeNode*root, int &ans, int low, int high){
        if(!root)
        return;
        if(root->val >=low && root->val<=high)
        ans+=root->val;
        search(root->left,ans,low,high);
        search(root->right,ans,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
        return 0;
        int ans = 0;
        search(root,ans,low,high);
        return ans;
    }
};