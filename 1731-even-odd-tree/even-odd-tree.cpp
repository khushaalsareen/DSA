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
    bool levelOrder(TreeNode*root){
        int level = -1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            level++;
            int val = -1;
            for(int i=0;i<sz;i++){
                TreeNode*node = q.front();
                q.pop();
                if(level%2 == 0){
                    if(node->val % 2 ==0)
                        return false;
                    if(val == -1){
                        val = node->val;
                    }
                    else{
                        if(node->val <= val)
                        return false;
                        else
                        val = node->val;
                    }
                }
                else{
                    if(node->val % 2 !=0)
                        return false;
                    if(val == -1){
                        val = node->val;
                    }
                    else{
                        if(node->val >= val)
                        return false;
                        else
                        val = node->val;
                    }
                }
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
        return true;
        return levelOrder(root);
    }
};