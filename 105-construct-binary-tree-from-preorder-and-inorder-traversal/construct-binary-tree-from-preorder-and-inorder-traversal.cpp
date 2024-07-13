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
    TreeNode* construct(int ps,int pe, int is, int ie,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&m) {
        if(is>ie)
        return NULL;

        TreeNode*root = new TreeNode(preorder[ps]); // created a root node
        int i = m[preorder[ps]];
        int prevElements = i-is;
       
        root->left = construct(ps+1,ps + prevElements,is,i-1,preorder,inorder,m);
        root->right = construct(ps+prevElements+1,pe,i+1,ie,preorder,inorder,m);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
        return NULL;
        int n = preorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        return construct(0,n-1,0,n-1,preorder,inorder,m);
    }
};