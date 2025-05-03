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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * p1 = head;
        ListNode * p2 = head;
        while(p2 && n){
            p2 = p2->next;
            n--;
        }
        if(p2 == NULL && n == 0)
        return head->next;
        else if(p2 == NULL)
        return head;
        else{
            while(p2->next){
                p1 = p1->next;
                p2 = p2->next;
            }
            cout<<p1->val << " "<<p2->val; 
            p1->next = p1->next->next;
            return head;
        }
    }
};