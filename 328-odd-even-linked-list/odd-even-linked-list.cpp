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
        if(!head || !head->next)
        return head;

        ListNode * oddHead = NULL;
        ListNode * evenHead = NULL;
        ListNode * oddTail = oddHead;
        ListNode * evenTail = evenHead;
        ListNode * tmp = head;
        bool flg = true;
        while(tmp){
            if(flg){
                // odd index node
                if(oddHead == NULL){
                    oddHead = tmp;
                    oddTail = oddHead;
                }
                else{
                    oddTail->next = tmp;
                    oddTail = oddTail->next;
                }
            }
            else{
                if(evenHead == NULL){
                    evenHead = tmp;
                    evenTail = evenHead;
                }
                else{
                    evenTail->next = tmp;
                    evenTail = evenTail->next;
                }
            }
            flg = flg==true? false: true;
            tmp = tmp->next;
        }
        oddTail->next = NULL;
        evenTail->next = NULL;
        oddTail->next = evenHead;
        return oddHead;
    }
};