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
    unordered_map<long int,int>m;
    
    void f(TreeNode * root, long int psum, int target){
        if(!root)
        return;
        psum+=root->val;
        if(m.find(psum-target)!=m.end())
        cnt+=m[psum-target];
        m[psum]++;
        f(root->left,psum,target);
        f(root->right,psum,target);
        m[psum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
        return 0;
        m[0] = 1;
        f(root,0*1LL,targetSum);
        return cnt;
    }
};