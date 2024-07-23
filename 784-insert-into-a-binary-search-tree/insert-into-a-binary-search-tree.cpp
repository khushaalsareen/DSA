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
        if(!root){
            return new TreeNode(val);
        }
        TreeNode*temp = root;
        TreeNode*prev = NULL;
        while(temp){
            prev = temp;
            if(temp->val > val)
            temp = temp->left;
            else
            temp = temp->right;
        }
        if(val>prev->val)
        prev->right = new TreeNode(val);
        else
        prev->left = new TreeNode(val);
        return root;
    }
};