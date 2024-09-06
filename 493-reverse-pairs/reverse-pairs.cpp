class Solution {
public:
    void countPairs(vector<int>&nums, int s1, int e1, int s2, int e2, int &ans){
        int n = nums.size();
        int i =s1;
        int idx = s2;
        while(i<=e1){
            for(;idx<=e2;idx++){
                if(nums[i]>2*1LL*nums[idx])
                ans+=e1-i+1;
                else
                break;
            }
            i++;
        }
    }
    void merge(vector<int>&nums, int s1, int e1, int s2, int e2, vector<int>&temp){
        int i = s1;
        int j = s2;
        int c = s1;
        while(i<=e1 && j<=e2){
            if(nums[i]<nums[j]){
                temp[c++] = nums[i++];
            }
            else{
                temp[c++] = nums[j++];
            }
        }
        while(i<=e1){
            temp[c++] = nums[i++];
        }
        while(j<=e2){
            temp[c++] = nums[j++];
        }
        for(int k=s1;k<=e2;k++){
            nums[k] = temp[k];
        }
    }
    void mergeSort(vector<int>&nums, int l, int h, int &ans,vector<int>&temp){
        if(l==h)
        return;
        int m = l + (h-l)/2;
        mergeSort(nums,l,m,ans,temp);
        mergeSort(nums,m+1,h,ans,temp);
        countPairs(nums,l,m,m+1,h,ans);
        merge(nums,l,m,m+1,h,temp);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
        int ans =0;
        mergeSort(nums,0,n-1,ans,temp);
        return ans;
    }
};