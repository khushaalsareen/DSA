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
      static  bool cmp(pair<int,TreeNode*>&p1,pair<int,TreeNode*>&p2){
        if(p1.first == p2.first)
        return p1.second->val < p2.second->val;
        return p1.first < p2.first;
      }
public:
    // assigning horizonatl and vertical
    void levelOrder(TreeNode*root,unordered_map<int,vector<pair<int,TreeNode*>>>&m,int &mini, int &maxi){
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> p = q.front();
            q.pop();
            TreeNode* currNode = p.first;
            int currVert = p.second.first;
            int currHori = p.second.second;
            mini = min(mini,currVert);
            maxi = max(maxi,currVert);
            m[currVert].push_back({currHori,currNode});
            if(currNode->left)
            q.push({currNode->left,{currVert-1,currHori+1}});
            if(currNode->right)
            q.push({currNode->right,{currVert+1,currHori+1}});
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int,vector<pair<int,TreeNode*>>>m;
        int mini = 1e9;
        int maxi = -1e9;
        levelOrder(root,m,mini,maxi);
        for(auto &it:m){
            cout<<"vertical "<<it.first<<" ";
            for(auto j:it.second){
                cout<<"Horizonatl "<<j.first<<" "<<"Value "<<j.second->val<<endl;
            }
            sort(it.second.begin(),it.second.end(),cmp);
        }
        for(int i=mini;i<=maxi;i++){
            vector<int>v;
            for(auto it:m[i]){
                v.push_back(it.second->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};