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
    int cnt = 0;
public:
    void check(TreeNode*root,long long int target, int &cnt){
        if(!root) return;
        if(target==(long long)root->val) cnt++;
        check(root->left,target*1LL-root->val,cnt);
        check(root->right,target*1LL-root->val,cnt);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        check(root,targetSum,cnt);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return cnt;
    }
};