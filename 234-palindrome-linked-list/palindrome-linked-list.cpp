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
    ListNode * getMiddle(ListNode*head){
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = NULL;
        while(fast && fast->next && fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode*head){
        ListNode * curr = head;
        ListNode * prev = NULL;
        while(curr){
            ListNode * tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;
        ListNode * mid = getMiddle(head);
        ListNode * h2 = mid->next;
        mid->next = NULL;
        h2 = reverse(h2);
        ListNode*h1 = head;
        while(h1 && h2){
            if(h1->val != h2->val)
            return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};