class Solution {
public:

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();
        int n4 = nums4.size();
        unordered_map<long long int,int>m1;
        unordered_map<long long int,int>m2;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                m1[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<n3;i++){
            for(int j=0;j<n4;j++){
                m2[nums3[i]+nums4[j]]++;
            }
        }
        int ans = 0;
        for(auto it:m1){
            // it is pair
            int target = -1*it.first;
            if(m2.find(target)!=m2.end()){
                ans+=(it.second*m2[target]);
            }
        }
        return ans;
    }
};