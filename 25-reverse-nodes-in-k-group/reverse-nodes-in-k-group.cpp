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
            ListNode*temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
        return NULL;
        ListNode*curr = head;
        int cnt = 1;
        ListNode*temp = head;
        while(cnt<k && temp!= NULL){
            cnt++;
            temp = temp->next;
        }
        if(!temp || cnt<k)
        return head;

        ListNode* next = temp->next;
        temp->next = NULL; //isolated first k nodes
        ListNode* newHead = reverse(curr);
        curr->next = reverseKGroup(next, k);
        return newHead;
    }
};