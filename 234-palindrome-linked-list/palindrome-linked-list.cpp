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
            ListNode*tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    ListNode * getMiddle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;

        ListNode * middle = getMiddle(head);
        ListNode * reversedHead = reverse(middle->next);
        middle->next = NULL;
        ListNode * tmp1 = head;
        ListNode * tmp2 = reversedHead;
        while(tmp1 && tmp2){
            if(tmp1->val !=tmp2->val)
            return false;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return true;
    }
};