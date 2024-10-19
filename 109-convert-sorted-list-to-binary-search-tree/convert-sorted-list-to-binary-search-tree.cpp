/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* convertToBST(vector<int>&nums, int l, int h){
        if(l>h)
        return NULL;
        int mid = l+(h-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convertToBST(nums,l,mid-1);
        root->right = convertToBST(nums,mid+1,h);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
        return NULL;
        vector<int>v;
        ListNode*temp = head;
        int n = 0;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
            n++;
        }
        return convertToBST(v,0,n-1);
    }
};