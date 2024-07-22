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
    void inorder(TreeNode*root, vector<int>&ans){
        TreeNode* temp = root;
        while(temp){
            if(temp->left == NULL){
                ans.push_back(temp->val);
                temp = temp->right;
            }
            else{
                TreeNode*leftNode = temp->left;
                while(leftNode->right != NULL && leftNode->right != temp){
                    leftNode=leftNode->right;
                }
                if(leftNode->right == NULL){
                    leftNode->right = temp;
                    temp = temp->left;
                }
                else{
                    leftNode->right = NULL;
                    ans.push_back(temp->val);
                    temp = temp->right;
                }

            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
        return ans;
        inorder(root,ans);
        return ans;
    }
};