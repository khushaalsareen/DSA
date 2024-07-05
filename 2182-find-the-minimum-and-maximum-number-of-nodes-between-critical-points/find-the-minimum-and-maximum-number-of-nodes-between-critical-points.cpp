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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        int first = -1;
        int prev = -1;
        int curr = -1;
        int next = -1;
        int lastIdx = -1;
        int minAns = 1e9;
        int cnt = 0;
        int munni = 0;
        ListNode * temp = head;
        while(temp->next){
            cnt++;
            curr = temp->val;
            next = temp->next->val;
            if(prev!=-1){
                if((curr>prev && curr>next) || (curr<prev && curr<next)){
                    munni++;
                    if(lastIdx==-1)
                    {
                        first = cnt;
                        lastIdx = cnt;
                    }
                    else{
                        minAns = min(minAns, cnt - lastIdx);
                        lastIdx = cnt;
                    }

                }
            }
            prev = curr; 
            temp = temp->next;
        }
        if(munni <2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        // if(munni<2)
        ans.push_back(minAns);
        int maxi = lastIdx - first;
        ans.push_back(maxi);
        return ans;
    }
};