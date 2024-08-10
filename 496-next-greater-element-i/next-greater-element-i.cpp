class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        
        vector<int>NGE(sz2,-1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<sz2;i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                NGE[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0;i<sz2;i++){
            m[nums2[i]] = i;
        }
        for(int i=0;i<sz1;i++){
            ans.push_back(NGE[m[nums1[i]]]);
        }
        return ans;
    }
};