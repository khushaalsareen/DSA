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
      ListNode * reverse(ListNode* head){
        if(!head || !head->next)
        return head;
        ListNode * curr = head;
        ListNode * nextNode = curr->next;
        curr->next = NULL;
        ListNode * newHead = reverse(nextNode);
        nextNode->next = curr;
        return newHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * tmp = head;
        ListNode*prev = NULL;
        int cnt = 0;
        while(cnt<k && tmp!=NULL){
            cnt++;
            prev = tmp;
            tmp = tmp->next;
        }
        if(cnt<k)
        return head;
        ListNode * nextNode = tmp;
        prev->next = NULL;
        ListNode * newHead = reverse(head);
        head->next = reverseKGroup(nextNode,k);
        return newHead; 
    }
};