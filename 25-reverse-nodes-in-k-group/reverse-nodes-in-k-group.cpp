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
    ListNode * reverse(ListNode * head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr){
            ListNode * tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next)
        return head;
        ListNode * tmp = head;
        int cnt = 0;
        for(int i=0;i<k-1 && tmp;i++){
            tmp = tmp->next;
            cnt++;
        }
        if(cnt+1<k || tmp==NULL)
        return head;

        ListNode * next = tmp->next;
        tmp->next = NULL;
        ListNode * revHead = reverse(head);
        head->next = reverseKGroup(next,k);
        return revHead;
    }
};