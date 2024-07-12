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
 
static bool cmp(pair<int,int>p1, pair<int,int>p2){
    if(p1.second == p2.second)
    return p1.first<p2.first;
    return p1.second<p2.second;
}
void levelOrder(TreeNode* root, vector<vector<int>>& ans, unordered_map<int, vector<pair<int,int>>>& m, int& mini, int& maxi) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int prevVert = -1;
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        for(int i=0;i<sz;i++){
        pair<TreeNode*, int> p = q.front();
        q.pop();
        TreeNode* currNode = p.first;
        int currVert = p.second;
        
        mini = min(mini, currVert);
        maxi = max(maxi, currVert);
        
        m[currVert].push_back({currNode->val,level});

        if (currNode->left) {
            q.push({currNode->left, currVert - 1});
        }

        if (currNode->right) {
            q.push({currNode->right, currVert + 1});
        }
    }
        level++;
        
    }
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>>ans;
    if (!root) {
        return ans;
    }

    unordered_map<int, vector<pair<int,int>>> m;
    int maxi = -1;
    int mini = 1e9;
    
    levelOrder(root, ans, m, mini, maxi);
    
    for (int i = mini; i <= maxi; i++) {
        sort(m[i].begin(),m[i].end(),cmp);
        int sz = m[i].size();
        vector<int>v;
       for(auto it:m[i]){
        v.push_back(it.first);
       }
       ans.push_back(v);
    }
    
    return ans;
}
};