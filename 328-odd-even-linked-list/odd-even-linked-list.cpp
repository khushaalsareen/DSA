class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int cnt = 1;
        ListNode*temp1=NULL,*temp2=NULL,*head1=NULL,*head2=NULL;
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode*temp = head;
        while(temp){
            if(cnt%2 == 0) // even
            {
                if(temp2==NULL){
                temp2 = temp;
                head2 = temp;
                }
                else{
                temp2->next = temp;
                temp2 = temp2->next;
                }
            }
            else {
                if(temp1==NULL){
                temp1 = temp;
                head1 = temp;
                }
                else{
                temp1->next = temp;
                temp1 = temp1->next;
                }
            }
            temp = temp->next;
            cnt+=1;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        temp1->next = head2;
        return head1;
    }
};