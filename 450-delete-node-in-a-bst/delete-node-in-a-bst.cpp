class Solution {
    TreeNode* par = nullptr;
    TreeNode* toDel = nullptr;

public:
    bool search(TreeNode* root, int key, TreeNode* prev) {
        if (!root) return false;
        if (root->val == key) {
            par = prev;
            toDel = root;
            return true;
        }
        return search(root->left, key, root) || search(root->right, key, root);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        bool found = search(root, key, nullptr);
        if (!found) return root;

        // Case: Node has two children
        if (toDel->left && toDel->right) {
            TreeNode* pred = toDel->left;
            TreeNode* predParent = nullptr;
            while (pred->right) {
                predParent = pred;
                pred = pred->right;
            }
            toDel->val = pred->val;
            // Now delete pred
            if (!predParent)
                toDel->left = pred->left; // pred was immediate left
            else
                predParent->right = pred->left;
        }
        // Case: Node has one child or is a leaf
        else {
            TreeNode* child = toDel->left ? toDel->left : toDel->right;
            if (!par) {
                // deleting the root node
                return child;
            }
            if (par->left == toDel) par->left = child;
            else par->right = child;
        }

        return root;
    }
};
