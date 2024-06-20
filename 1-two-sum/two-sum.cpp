class Solution {
public:
    int binarySearch(vector<pair<int,int>>&nums, int l, int h, int target){
        int mid ;
        while(l<=h){
            mid = l+(h-l)/2;
        if(nums[mid].first==target)
        return nums[mid].second;
        else if(nums[mid].first>target)
        h = mid -1;
        else 
        l = mid + 1;
        } 
        
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(auto it:v){
            cout<<it.first <<"  "<<it.second<<endl;
        }
        for(int i=0;i<nums.size();i++){
            int rem = target - v[i].first;
            int ans = binarySearch(v,i+1,nums.size()-1,rem);
            if(ans!=-1)
            return {v[i].second,ans};
        }
        return {-1};
    }
};