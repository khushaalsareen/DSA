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
  
       vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans(k, nullptr);  // Initialize answer vector with k null pointers
    
    if (!head) return ans;  // If the list is empty, return the vector with all nulls

    int cnt = 0;
    ListNode* temp = head;
    while (temp) {  // Count the number of nodes in the list
        cnt++;
        temp = temp->next;
    }

    int part_size = cnt / k;  // Minimum size of each part
    int extra = cnt % k;      // Extra nodes to distribute

    temp = head;
    for (int i = 0; i < k && temp; ++i) {
        ans[i] = temp;  // The start of the i-th part
        int current_size = part_size + (extra > 0 ? 1 : 0);  // Add an extra node to this part if needed
        extra--;

        for (int j = 1; j < current_size; ++j) {  // Move to the end of the current part
            temp = temp->next;
        }
        
        ListNode* next_part = temp->next;  // Save the next part's head
        temp->next = nullptr;  // Break the list to separate the current part
        temp = next_part;  // Move to the next part
    }
    
    return ans;
}

};