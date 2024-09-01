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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode*temp = dummy;
        unordered_map<int,int>m;
        for(auto it:nums)
        m[it]++;
        while(temp->next){
            if(m.find(temp->next->val)==m.end()){
                temp = temp->next;
            }
            else{
                ListNode*nextNode = temp->next->next;
                ListNode* toDelete = temp->next;
                temp->next = nextNode;
                delete(toDelete);
            }
        }
        return dummy->next;
    }
};