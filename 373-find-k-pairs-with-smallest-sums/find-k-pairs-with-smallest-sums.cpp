class Solution {
private:
    struct comp {
        vector<int>& nums1;
        vector<int>& nums2;

        comp(vector<int>& nums1_ref, vector<int>& nums2_ref) : nums1(nums1_ref), nums2(nums2_ref) {}

        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) const {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        }
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(comp(nums1, nums2)); // Pass nums1 and nums2 to comp constructor
        pq.push({0,0});
        int cnt = 0;
        set<pair<int,int>> s;
        s.insert({0,0});
        while(!pq.empty() && cnt != k) {
            pair<int,int> p = pq.top();
            pq.pop();
            cnt++;
            int i = p.first;
            int j = p.second;
            ans.push_back({nums1[i], nums2[j]});
            if(i + 1 < n && s.find({i + 1, j}) == s.end()) {
                pq.push({i + 1, j});
                s.insert({i + 1, j});
            }
            if(j + 1 < m && s.find({i, j + 1}) == s.end()) {
                pq.push({i, j + 1});
                s.insert({i, j + 1});
            }
        }
        return ans;
    }
};
