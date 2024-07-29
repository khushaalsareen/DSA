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
class BSTIterator {
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        TreeNode*tmp = s.top();
        s.pop();
        if(tmp->right){
            TreeNode*left = tmp->right;
            while(left){
                s.push(left);
                left = left->left;
            }
        }
        return tmp->val;
    }
    
    bool hasNext() {
        return s.size()!=0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */