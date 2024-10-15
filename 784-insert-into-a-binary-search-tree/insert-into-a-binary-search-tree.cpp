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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        return new TreeNode(val);
        TreeNode* tmp = root;
        TreeNode*par = NULL;
        while(tmp){
            par = tmp;
            if(tmp->val > val)
            tmp = tmp->left;
            else
            tmp = tmp->right;
        }
        if(par->val > val){
            par->left = new TreeNode(val);
        }
        else
        par->right = new TreeNode(val);
        return root;
    }
};