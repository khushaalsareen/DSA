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
    void generate(TreeNode*root,int target, vector<int>&v,vector<vector<int>>&ans){
        if(!root)
        return;
        // if(root->val > target) return;
        if(!root->left && !root->right){
            if(root->val == target)
            {
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
           
            }
            return;
        }

        v.push_back(root->val);
        // cout<<"Yes"<<" "<<root->val<<" ";
        generate(root->left,target-root->val,v,ans);
        generate(root->right,target-root->val,v,ans);
        v.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(!root)
        return ans;
        vector<int>v;
        generate(root,targetSum,v,ans);
        return ans;
    }
};