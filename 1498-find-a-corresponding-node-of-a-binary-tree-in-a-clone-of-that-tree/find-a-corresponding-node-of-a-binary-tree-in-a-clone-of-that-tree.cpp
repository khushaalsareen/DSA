/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* findNode(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(!original)
        return NULL;
        if(original == target){
            return cloned;
        }
        
        TreeNode*t1 = findNode(original->left,cloned->left,target);
        TreeNode*t2 = findNode(original->right,cloned->right,target);
        return t1==NULL?t2:t1;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return findNode(original,cloned,target);
    }
};