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
    pair<bool,int> height(TreeNode*root){
        if(!root)
        return {true,0};

        pair<bool,int> left = height(root->left);
        pair<bool,int> right = height(root->right);

        bool b = left.first && right.first && abs(left.second - right.second)<=1;
        int lh = left.second;
        int rh = right.second;
        int h =  1 + max(lh,rh);
        return {b,h};
    }
    bool isBalanced(TreeNode* root) {
        return height(root).first;
    }
};