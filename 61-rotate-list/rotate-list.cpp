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

// 1   k = 5

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        return NULL;
        int len = 0;
        ListNode*temp = head;
        ListNode*tail = NULL;
        while(temp){
            tail = temp;
            len++;
            temp = temp->next;
        }
        k  = k%len;
        if(k == 0)
        return head;
        int cnt = 0;
        temp = head;
        while(cnt<len - k - 1){
            temp = temp->next;
            cnt++;
        }
        ListNode* sp = temp->next;
        temp->next = NULL;
        tail->next = head;
        return sp;

    }
};