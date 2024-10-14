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
        if(!root)
        return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int target) {
        vector<int>ans;
        if(!root->left && !root->right)
        return false;
        inorder(root,ans);
        int i = 0;
        int j = ans.size()-1;
        while(i<j){
            int sum = ans[i] + ans[j];
            if(ans[i]+ans[j]==target)
            return true;
            else if(sum>target)
            j--;
            else
            i++;
        }
        return false;
    }
};