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
    TreeNode* buildTree(vector<int>&nums, int l, int h){
        if(l>h)
        return NULL;
        int m = l+(h-l)/2;
        TreeNode * root = new TreeNode(nums[m]);
        root->left = buildTree(nums,l,m-1);
        root->right = buildTree(nums,m+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildTree(nums,0,n-1);
    }
};