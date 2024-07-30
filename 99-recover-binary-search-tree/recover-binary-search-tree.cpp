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
    void inorder(TreeNode*root, vector<int>&v){
        if(!root)
        return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void inorderAgain(TreeNode*root, vector<int>&v, int &i){
        if(!root)
        return;
        inorderAgain(root->left,v,i);
        root->val = v[i++];
        inorderAgain(root->right,v,i);
    }
    void recoverTree(TreeNode* root) {
        if(!root)
        return;
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end()); // actual sorted result I need in array
        int i = 0;
        inorderAgain(root,v,i);
        
    }
};