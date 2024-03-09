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
    void getParent(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&m,TreeNode*parent){
        if(!root) return;
        m.insert({root,parent});
        getParent(root->left,m,root);
        getParent(root->right,m,root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)
        return {};
        unordered_map<TreeNode*,TreeNode*>m;
        vector<int>ans;
        getParent(root->left,m,root);
        getParent(root->right,m,root);
        queue<pair<TreeNode*,int>>q;
        q.push({target,k});
        unordered_set<TreeNode*>s;
        while(!q.empty()){
            pair<TreeNode*,int>p = q.front();
            q.pop();
            TreeNode*currNode = p.first;
            int currDist = p.second;
            s.insert(currNode);
            if(currDist==0)
            ans.push_back(currNode->val);
            else{
                if(currNode->left && s.find(currNode->left)==s.end())
                q.push({currNode->left,currDist-1});
                if(currNode->right && s.find(currNode->right)==s.end())
                q.push({currNode->right, currDist-1});
                if(m.find(currNode)!=m.end() && s.find(m[currNode])==s.end())
                q.push({m[currNode],currDist-1});
            }
        }
        return ans;
    }
};