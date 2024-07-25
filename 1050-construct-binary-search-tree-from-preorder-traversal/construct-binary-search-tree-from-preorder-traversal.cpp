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
    TreeNode* generateTree(int ps, int pe, int is, int ie,vector<int>&preorder, vector<int>&inorder){
        if(ps>pe)
        return NULL;

        TreeNode * root = new TreeNode(preorder[ps]);
        int i;
        for( i=0;i<inorder.size();i++){
            if(preorder[ps]==inorder[i])
            break;
        }
        int leftnodes = i - is;
        root->left = generateTree(ps+1,ps+leftnodes,is,i-1,preorder,inorder);
        root->right = generateTree(ps + leftnodes + 1,pe,i+1,ie,preorder,inorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int n = inorder.size();
        return generateTree(0,n-1,0,n-1,preorder,inorder);
        
    }
};