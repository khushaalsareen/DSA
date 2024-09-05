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
class Solution {
public:
    ListNode* reverse(ListNode*head){
        ListNode*prev = NULL;
        ListNode*curr = head;
        while(curr){
            ListNode*temp= curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
        return NULL;
        if(k == 1)
        return head;
        int cnt = 0;
        ListNode*temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        if(cnt<k)
        return head;
        temp = head;
        ListNode*prev = NULL;
        cnt = 0;
        while(cnt<k-1){
            cnt++;
            temp = temp->next;
        }
        ListNode*nextnode = temp->next;
        temp->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(nextnode,k);
        return newHead;
    }
};