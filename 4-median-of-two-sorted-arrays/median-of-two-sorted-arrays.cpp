// class Solution {
// public:
//     double findAns(vector<int>& nums1, vector<int>& nums2){
//         int n1 = nums1.size(); //(n1<n2)
//         int n2 = nums2.size();

//         if(n1==0 && n2>0){
//             if(n2%2 != 0)
//             return nums2[n2/2];
//             else
//             return (nums2[n2/2] + nums2[n2/2 - 1])/2.0;
//         }
//         if(n2==0){
//             return 0;
//         }
//         int l = 0;
//         int h = nums1.size();
//         int x;
//         while(l<=h){
//             x = l+(h-l)/2;
//             int y = (n1+n2)/2 - x;
//             int a1 = x==0 ? INT_MIN : nums1[x-1];
//             int b1 = y == 0 ? INT_MIN: nums2[y - 1];
//             int a2 = x == n1 ? INT_MAX : nums1[x];
//             int b2 = y == n2 ? INT_MAX : nums2[y];
            
//             if(a1<=b2 && a2<=b1){
//                 if((n1+n2)%2 ==0)
//                 return (max(a1,b1)+min(a2,b2))/2.0;
//                 else
//                 return min(a2,b2);
//             }
//             else if(a1>b2)
//             h = x-1;
//             else
//             l = x+1;
//         }
//         return -1;
//     }
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        return nums1.size()<=nums2.size() ? findAns(nums1,nums2) : findAns(nums2,nums1);

//     }
// };

class Solution {
public:
    double solve(vector<int>&nums1,vector<int>&nums2){
         int m = nums1.size();
         int n = nums2.size();
        
        if(m==0 && n>0){
            if(n%2 != 0)
            return nums2[n/2];
            else
            return (nums2[n/2] + nums2[n/2 - 1])/2.0;
        }
        if(n==0 && m==0){
            return 0;
        }
        int l = 0;
        int h = m;
        
        while(l<=h){
            int x = l+(h-l)/2;
            int y = (m+n)/2 - x;
            int l1 = x==0 ? INT_MIN :nums1[x-1];
            int l2 = y==0 ? INT_MIN :nums2[y-1];
            int r1 = x==m ? INT_MAX :nums1[x];
            int r2 = y==n ? INT_MAX :nums2[y];
            
            if(l1<=r2 && l2<=r1){ // correct partition
                if((m+n)%2 == 0)
                return (max(l1,l2) + min(r1,r2))/2.0;
                else
                return min(r1,r2);
            }
            else{
                if(l1>r2){
                    h = x-1;
                }
                else{ // r1< l2
                    l = x + 1;
                }
            }
            
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return nums1.size()<=nums2.size() ? solve(nums1,nums2) : solve(nums2,nums1);
        
    }
};