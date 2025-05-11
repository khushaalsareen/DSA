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
    stack<TreeNode*>s2;
    void leftPush(TreeNode*root){ // this is basically doing in ascending order pushing on stack
        if(!root)
        return;
        TreeNode * tmp = root;
        while(tmp){
            s.push(tmp);
            tmp = tmp->left;
        }
    }
    void rightPush(TreeNode*root){
        if(!root)
        return;
        TreeNode*tmp = root;
        while(tmp){
            s2.push(tmp);
            tmp = tmp->right;
        }        
    }
public:
    BSTIterator(TreeNode* root) {
        leftPush(root);
        rightPush(root);
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

    int prev(){
        TreeNode * prevNode = s2.top();
        s2.pop();
        rightPush(prevNode->left);
        return prevNode->val;
    }

    int hasPrev(){
        return s2.size()>0;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root->left && !root->right)
        return false;

        BSTIterator l(root);
        BSTIterator r(root);

        int i = l.next();
        int j = r.prev();
        while(i<j){
            if(i+j == k)
            return true;
            else if(i+j<k)
            i = l.next();
            else
            j = r.prev();
        }
        return false;
    }
};