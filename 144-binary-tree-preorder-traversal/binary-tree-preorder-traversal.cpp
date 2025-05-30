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
    vector<int>ans;
public:
    void traverse(TreeNode * root){
        if(!root)
        return;

        ans.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
        return ans;
        traverse(root);
        return ans;
    }
};