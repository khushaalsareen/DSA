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
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
            ListNode* newHead = reverse(head);
            ListNode* temp = newHead;
            ListNode* prev = NULL;
            int carry = 0;
            while(temp){
                int num =  temp->val*2 + carry;
                temp->val = num%10;
                carry = num/10;
                prev = temp;
                temp = temp->next; 
            }
            if(carry!=0)
            prev->next = new ListNode(carry);
            return reverse(newHead);
    }
};