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
    void generateParent(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {q.push(node->left);
             m[node->left] = node;
            }
            if(node->right)
           { q.push(node->right);
             m[node->right] = node;
           }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)
        return {};
        unordered_map<TreeNode*,TreeNode*>m;
        generateParent(root,m);
        queue<pair<TreeNode*,int>>q;
        q.push({target,k});
        unordered_set<TreeNode*>visited;
        vector<int>ans;
        visited.insert(target);
        while(!q.empty()){
            pair<TreeNode*, int>p = q.front();
            q.pop();
            TreeNode*currNode = p.first;
            int currDist = p.second;
            if(currDist<0)
            break;
            if(currDist==0)
            ans.push_back(currNode->val);
            if(currNode->left && visited.find(currNode->left)==visited.end()){
                q.push({currNode->left,currDist-1});
                visited.insert(currNode->left);
            }
            if(currNode->right && visited.find(currNode->right)==visited.end()){
                q.push({currNode->right,currDist-1});
                visited.insert(currNode->right);
            }
            if(m[currNode] && visited.find(m[currNode])==visited.end()){
                q.push({m[currNode],currDist-1});
                visited.insert(m[currNode]);
            }
        }
        return ans;
    }
};