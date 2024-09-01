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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        return NULL;
        if(head->next == NULL)
        return head;
        ListNode * head1 = head, *head2 = head->next;
        ListNode*tail1 = head1, *tail2 = head2;
        ListNode*tmp1 = head1, *tmp2 = head2;
        while(tmp1 &&tmp2){
            tmp1->next = tmp2->next;
            tail1 = tmp1;
            tmp1 = tmp1->next;
            if(tmp1){
                tmp2->next = tmp1->next;
                tail2 = tmp2;
                tmp2 = tmp2->next;
            }
        }
        if(tmp1)
        tmp1->next = head2;
        else
        tail1->next = head2;
        return head1;
    }
};