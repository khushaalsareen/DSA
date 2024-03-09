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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                return root->left;
            } else if (root->left == nullptr && root->right != nullptr) {
                return root->right;
            } else {
                int maxVal = findMax(root->left);
                root->val = maxVal;
                root->left = deleteNode(root->left, maxVal);
                // return root;
            }
        }
        return root;
    }

    int findMax(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->val;
    }
};
