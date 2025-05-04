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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next)
        return head;

        int len = 0;
        ListNode * tmp = head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        k = k%len;
        if(k==0)
        return head;
        tmp = head;
        for(int i=0;i<len-k-1;i++){
            tmp = tmp->next;
        }
        ListNode * nxt = tmp->next;
        tmp->next = NULL;
        ListNode * ptr = nxt;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = head;
        head = nxt;
        return head;
    }
};