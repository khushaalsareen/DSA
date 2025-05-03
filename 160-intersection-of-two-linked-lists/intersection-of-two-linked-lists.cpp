/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode * head){
        int cnt = 0;
        ListNode * tmp = head;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
            int diff = abs(lenA-lenB);
        if(lenA>lenB){
            ListNode * tmp = headA;
            while(diff--){
                tmp = tmp->next;
            }
            headA = tmp;
        }
        else if(lenA<lenB){
            ListNode * tmp = headB;
            while(diff--){
                tmp = tmp->next;;
            }
            headB = tmp;
        }
        ListNode * t1 = headA;
        ListNode * t2 = headB;
        if(t1 == t2)
        return t1;
        while(t1 && t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2)
            return t1;
        }
        return NULL;
    }
};