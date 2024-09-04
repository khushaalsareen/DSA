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
    void f(TreeNode*root, int last, int &cnt){
        if(!root)
        return;

        if(root->val >=last)
        cnt++;
        f(root->left,max(last,root->val),cnt);
        f(root->right,max(last,root->val),cnt); 
    }
    int goodNodes(TreeNode* root) {
        if(!root)
        return 0;
        int cnt = 1;
        f(root->left,root->val,cnt);
        f(root->right,root->val,cnt);
        return cnt;
    }
};