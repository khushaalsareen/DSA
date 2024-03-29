/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*currNode = q.front();
            q.pop();
            if(currNode==NULL)
            s.append("#,");
            else
            s.append(to_string(currNode->val)+",");
            if(currNode){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data);
        string str;
        queue<TreeNode*>q;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode*curr = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                curr->left = NULL;
            }
            else{
                TreeNode*newNode = new TreeNode(stoi(str));
                q.push(newNode);
                curr->left = newNode;
            }
            getline(s,str,',');
            if(str=="#")
                curr->right = NULL;
            else{
                TreeNode*newNode = new TreeNode(stoi(str));
                q.push(newNode);
                curr->right = newNode;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));