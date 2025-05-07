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
    unordered_map<TreeNode*,TreeNode*>parent;
    vector<int>ans;
    unordered_set<TreeNode*>s;
    void generateParent(TreeNode*root, TreeNode*par){
        if(!root)
        return;
        parent[root] = par;
        generateParent(root->left,root);
        generateParent(root->right,root);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans.clear();
        parent.clear();
        s.clear();
        if(!root->left && !root->right){
            if(k==0)
            {
                ans.push_back(root->val);
            }
            return ans;
        }
        generateParent(root->left,root);
        generateParent(root->right,root);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        s.insert(target);
        while(!q.empty()){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            TreeNode*currNode = p.first;
            int currDist = p.second;
            if(currDist == k)
            {ans.push_back(currNode->val);
            continue;
            }
            if(currNode->left && s.find(currNode->left)==s.end()){
                q.push({currNode->left,currDist+1});
                s.insert(currNode->left);
            }
            if(currNode->right && s.find(currNode->right)==s.end()){
                q.push({currNode->right,currDist+1});
                s.insert(currNode->right);
            }
            if(parent.find(currNode)!=parent.end() && s.find(parent[currNode])==s.end()){
                s.insert(parent[currNode]);
                q.push({parent[currNode],currDist+1});
            }
        }
        return ans;
    }
};