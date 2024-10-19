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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = NULL, *h2 = NULL, *t1 = NULL, *t2 = NULL;
        ListNode*temp = head;
        if(!head || !head->next)
        return head;

        while(temp){
            if(temp->val < x){
                if(h1 == NULL){
                    h1 = temp;
                    t1 = temp;
                    temp = temp->next;
                }
                else{
                    t1->next = temp;
                    temp = temp->next;
                    t1 = t1->next;
                }
            }
            else{
                if(h2 == NULL){
                    h2 = temp;
                    t2 = h2;
                    temp = temp->next;
                }
                else{
                    t2->next = temp;
                    temp = temp->next;
                    t2 = t2->next;
                }
            }
        }
        if(!t1)
        return h2;
        t1->next = h2;
        if(t2)
        t2->next = NULL;
        return h1;
    }
};