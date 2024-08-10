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
    ListNode*middle(ListNode*head){
        ListNode* slow =head;
        ListNode* fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode*merge(ListNode*h1, ListNode*h2){
        ListNode*head = NULL;
        ListNode*prev =NULL;
        ListNode*tmp1 = h1;
        ListNode*tmp2 = h2;
        while(tmp1 && tmp2){
            if(head==NULL){
                if(tmp1->val < tmp2->val){
                    head = tmp1;
                    prev = head;
                    tmp1 = tmp1->next;
                }
                else{
                    head = tmp2;
                    prev = head;
                    tmp2 = tmp2->next;
                }
            }
            else{
                if(tmp1->val < tmp2->val){
                    prev->next = tmp1;
                    tmp1 = tmp1->next;
                    prev = prev->next;
                }
                else{
                    prev->next = tmp2;
                    tmp2 = tmp2->next;
                    prev = prev->next;
                }
            }
    }
        if(tmp1)
        prev->next = tmp1;
        if(tmp2)
        prev->next = tmp2;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        return head;
        ListNode* midNode = middle(head); //
        cout<<midNode->val<<endl;
        ListNode*nextNode = midNode->next;
        midNode->next = NULL;
        ListNode*h1 = sortList(head);
        ListNode*h2 = sortList(nextNode);
        ListNode*newHead = merge(h1,h2);
        return newHead;
    }
};