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
    bool isSame(TreeNode*r1, TreeNode*r2){
        if(!r1 && !r2)
        return true;
        else if(!r1)
        return false;
        else if(!r2)
        return false;

        bool b1 = isSame(r1->left, r2->right);
        bool b2 = isSame(r1->right,r2->left);
        return b1 && b2 && r1->val == r2->val;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return true;
        return isSame(root->left,root->right);
    }
};