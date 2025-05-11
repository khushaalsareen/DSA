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
    void leftPush(TreeNode*root){
        if(!root)
        return;
        TreeNode * tmp = root;
        while(tmp){
            s.push(tmp);
            tmp = tmp->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        leftPush(root);
    }
    
    int next() {
        TreeNode * nxtNode = s.top();
        s.pop();
        leftPush(nxtNode->right);
        return nxtNode->val;
    }
    
    bool hasNext() {
        return s.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */