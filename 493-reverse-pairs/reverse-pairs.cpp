class Solution {
    int cnt = 0;
    void merge(vector<int>&arr, int s1, int e1, int s2, int e2,vector<int>&temp){
        int l1 = s1;
        int l2 = s2;
        int c1 = s1;
        while(l1<=e1 && l2<=e2){
            if(arr[l1]<=arr[l2])
            temp[c1++] = arr[l1++];
            else{
            // cnt+=e1-l1+1;
            temp[c1++] = arr[l2++];
            }
        }
        while(l1<=e1)
        temp[c1++] = arr[l1++];
        while(l2<=e2)
        temp[c1++] = arr[l2++];
        for(int i = s1;i<=e2;i++){
            arr[i] = temp[i];
        }
    }
    void countPairs(vector<int>&arr, int s1, int e1, int s2, int e2, vector<int>&temp){
        int ind = s2;
        for(int i=s1;i<=e1;i++){
            while(ind<=e2 && arr[i]>2*1LL*arr[ind]) ind++;
            cnt+=ind-s2;
        }
    }
    void mergeSort(vector<int>&arr, int l, int h, vector<int>&temp){
        if(l==h)
        return;
        int m = l+(h-l)/2;
        mergeSort(arr,l,m,temp);
        mergeSort(arr,m+1,h,temp);
        countPairs(arr,l,m,m+1,h,temp);
        merge(arr,l,m,m+1,h,temp);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp = nums;
        mergeSort(nums,0,n-1,temp);
        return cnt;
    }
};