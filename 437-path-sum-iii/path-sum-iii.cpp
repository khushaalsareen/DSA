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
    void f(TreeNode*root, long long int &sum, int target, int &cnt){
        if(!root)
        return;
        sum=sum + root->val;
        if(sum==target)
        cnt++;
        f(root->left,sum,target,cnt);
        f(root->right,sum,target,cnt);
        sum-=root->val;
    }
    void traverse(TreeNode*root, int &cnt, int target){
        if(!root)
        return;
        long long int sum = 0;
        f(root,sum,target,cnt);
        traverse(root->left,cnt,target);
        traverse(root->right,cnt,target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        if(!root)
        return 0;
        traverse(root,cnt,targetSum);
        return cnt;
    }
};