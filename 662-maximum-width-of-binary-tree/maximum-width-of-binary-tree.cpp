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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root)
        return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int sz = q.size();
            int minCurrLevel = q.front().second;
            int first = q.front().second;
            int last = q.back().second;
            if(last-first+1>ans)
            ans = last-first+1;
            for(int i=0;i<sz;i++){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                TreeNode*currNode = p.first;
                int currNum = p.second;
                int curr_id = currNum - minCurrLevel;
                if(currNode->left)
                q.push({currNode->left,2*1LL*curr_id + 1});
                if(currNode->right)
                q.push({currNode->right,2*1LL*curr_id + 2});
                if(i==0)
                first = currNum;
                if(i==sz-1)
                last = currNum;
            }
            
        }
        return ans;
    }
};