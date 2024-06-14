/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*prev = NULL;
        ListNode*temp = node;
        while(temp->next){
            temp->val = temp->next->val;
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        
    }
};