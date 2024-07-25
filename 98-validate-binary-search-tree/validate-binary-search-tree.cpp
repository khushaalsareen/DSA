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
    bool traversal(TreeNode*root,long long int mini,long long int maxi){
        if(!root)
        return true;
        if(root->val <=mini || root->val>=maxi)
        return false;
        bool b1 = traversal(root->left,mini,root->val);
        bool b2 = traversal(root->right,root->val,maxi);
        return b1 && b2;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
        return true;
        return traversal(root,LLONG_MIN,LLONG_MAX);
    }
};