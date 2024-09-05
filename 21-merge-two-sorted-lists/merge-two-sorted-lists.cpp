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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp1 = list1, *temp2 = list2;
        if(!list1)
        return list2;
        if(!list2)
        return list1;
        ListNode*newHead = NULL, * temp = NULL;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                if(newHead == NULL){
                    newHead = temp1;
                    temp = newHead;
                }
                else{
                    temp->next = temp1;
                    temp = temp->next;
                }
                temp1 = temp1->next;
            }
            else{
               if(newHead == NULL){
                    newHead = temp2;
                    temp = newHead;
                }
                else{
                    temp->next = temp2;
                    temp = temp->next;
                }
                temp2 = temp2->next; 
            }
        }
        if(temp1)
        temp->next = temp1;
        else
        temp->next = temp2;
        return newHead;
    }
};