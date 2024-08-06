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
    int len(ListNode*head){
        int cnt = 0;
        ListNode*temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        return NULL;
        int length = len(head);
        k = k%length;
        if(k==0)
        return head;
        // cout<<length<<endl;
        ListNode*temp = head;
        for(int i = 0;i<length-k-1;i++){
            temp = temp->next;  
        }
        ListNode*nextNode = temp->next;
        ListNode* newHead = nextNode;
        temp->next = NULL;
        while(nextNode && nextNode->next!=NULL){
            nextNode = nextNode->next;
        }
        nextNode->next = head;
        head = nextNode;
        return newHead;
    }
};