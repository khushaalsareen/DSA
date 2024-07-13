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
    TreeNode* construct(int ps, int pe,int is, int ie,vector<int>& inorder, vector<int>& postorder ){
        if(ps>pe || is>ie)
        return NULL;
        TreeNode*root = new TreeNode(postorder[pe]); // created root of tree
        int i;
        for( i=0;i<inorder.size();i++){
            if(postorder[pe]==inorder[i])
            break;
        }
        int prevElements = i - is;
        root->left = construct(ps,ps+prevElements-1,is,i-1,inorder,postorder);
        root->right = construct(ps+prevElements,pe-1,i+1,ie,inorder,postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return construct(0,n-1,0,n-1,inorder,postorder);
    }
};