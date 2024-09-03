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
     void generate( vector<vector<int>>&ans, vector<int>&v, TreeNode*root, int target, int &sum){
        if(!root)
        return;
        
        v.push_back(root->val);
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum == target)
            ans.push_back(v);
            v.pop_back();
            sum-=root->val;
            return;
        }
        
        generate(ans,v,root->left,target,sum);
        generate(ans,v,root->right,target,sum);
        
        v.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
         vector<int>v;
         int sum = 0;
         generate(ans,v,root,targetSum,sum);
         return ans;
    }
};