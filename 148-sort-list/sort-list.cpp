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
   ListNode* getMiddle(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


    ListNode * merge(ListNode* head1, ListNode * head2){
        ListNode * newHead = NULL;
        ListNode * tmp = NULL;
        ListNode * t1 = head1;
        ListNode * t2 = head2;
        while(t1 && t2){
            if(t1->val < t2->val){
                if(newHead == NULL){
                    newHead = t1;
                    tmp = t1;
                }
                else{
                    tmp->next = t1;
                    tmp = tmp->next;
                }
                t1  = t1->next;
            }
            else{
                if(newHead == NULL){
                    newHead = t2;
                    tmp = t2;
                }
                else{
                    tmp->next = t2;
                    tmp = tmp->next; 
                }
                t2  = t2->next;
            }
        }
        if(t1)
        tmp->next = t1;
        else
        tmp->next = t2;

        return newHead;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        return head;
        ListNode * mid = getMiddle(head);
        ListNode * nextNode = mid->next;
        mid->next = NULL;
        ListNode * head1 = sortList(head);
        ListNode * head2 = sortList(nextNode);
        return merge(head1,head2);
    }
};