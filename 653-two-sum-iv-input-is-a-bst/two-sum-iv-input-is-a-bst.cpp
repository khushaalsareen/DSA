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
    TreeNode*findPred(TreeNode*root, int value){
        TreeNode*ans = NULL;
        TreeNode*tmp = root;
        while(tmp){
            if(tmp->val < value){
                ans = tmp;
                tmp = tmp->right;
            }
            else
                tmp = tmp->left;
        }
        return ans;
    }

    TreeNode* findSucc(TreeNode*root, int value){
        TreeNode*ans = NULL;
        TreeNode*tmp = root;
        while(tmp){
            if(tmp->val > value){
                ans = tmp;
                tmp = tmp->left;
            }
            else
                tmp = tmp->right;
        }
        return ans;
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right)
        return false;

        TreeNode*leftNode = root;
        TreeNode*rightNode = root;
        while(leftNode->left){
            leftNode = leftNode->left;
        }
        while(rightNode->right){
            rightNode = rightNode->right;
        }
        // both left and right point to extreme points
        while(leftNode->val < rightNode->val){
            int sum = leftNode->val + rightNode->val;
            if(sum == k)
            return true;
            else if(sum>k){
                rightNode = findPred(root,rightNode->val);
            }
            else
                leftNode = findSucc(root,leftNode->val);
        }
        return false;
    }
};