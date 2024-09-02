/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findLCA(TreeNode*root, TreeNode*p, TreeNode*q){
        if(!root)
        return NULL;

        if(root==p || root== q)
        return root;
        TreeNode*r1 = findLCA(root->left,p,q);
        TreeNode*r2 = findLCA(root->right,p,q);
        if(!r1)
        return r2;
        else if(!r2)
        return r1;
        else
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p,q);
    }
};