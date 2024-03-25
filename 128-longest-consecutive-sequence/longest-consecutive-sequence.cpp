class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        if(nums.size()==0) return 0;
        for(auto it: nums)
        s.insert(it);

        vector<int>arr ; 
        for(auto it = s.begin(); it!=s.end(); it++){
            arr.push_back(*it);
        }

        int i = 0, j = 1;
        int ans = 1;
        while(j<arr.size()){
            if(arr[j]-arr[j-1]==1)
            j++;
            else{
                ans = max(ans, j-i);
                i = j;
                j = j+1;
            }
        }
        ans = max(ans, j - i);
        return ans;
    }
};