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
    ListNode* merge(ListNode*h1, ListNode*h2){
        if(!h1) return h2;
        if(!h2) return h1;
        ListNode*head = NULL, *temp = head;
        ListNode * t1 = h1, *t2 = h2;
        while(t1 && t2){
            if(t1->val < t2->val){
                if(head==NULL){
                    head = t1;
                    temp = t1;
                }
                else{
                    temp->next = t1;
                    temp = temp->next;
                }
                t1 = t1->next;
            }
            else{
                if(head==NULL){
                    head = t2;
                    temp = t2;
                }
                else{
                    temp->next = t2;
                    temp = temp->next;
                }
                t2 = t2->next;
            }
        }
        if(t1)
        temp->next = t1;
        else
        temp->next = t2;
        return head;
    }
    ListNode* mergeK(vector<ListNode*>&lists,int s,int e){
        if(s==e) return lists[s];
        int m = s+(e-s)/2;
       ListNode*h1 =  mergeK(lists,s,m);
       ListNode*h2 =  mergeK(lists,m+1,e);
       return merge(h1,h2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeK(lists,0,lists.size()-1);
    }
};