class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        s.push(0);
        // next smaller element
        vector<int>nse(n,n);
        for(int i=1;i<n;i++){
            while(!s.empty() && nums[i]<nums[s.top()]){
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        // previous gretaer
        s.push(n-1);
        vector<int>pge(n,-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && nums[i]>nums[s.top()]){
                pge[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int st = n;
        int end = n-1;
        for(int i=0;i<n;i++){
            if(nse[i]!=n){
                st = i;
                break;
            }
        }
        if(st == n)
        return 0;
        for(int i=n-1;i>=0;i--){
            if(pge[i]!=-1){
                end = i;
                break;
            }
        }
        return end - st + 1;
    }
};