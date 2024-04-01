class Solution {
public:
    int findGCD(int a,int b){
        if(a==0) return b;
        return findGCD(b%a,a);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int gcd = 0;
            for(int j=i;j<nums.size();j++){
                gcd = findGCD(gcd,abs(nums[j])); 
                if(gcd==k)
                {ans++;
                }
               
            }
        }
        return ans;
    }
};