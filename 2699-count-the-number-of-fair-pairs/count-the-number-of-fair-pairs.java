class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums); /*Sort  the array*/
        long cnt=0;
        for(int i=0;i<nums.length;i++){
            int currlower=lower-nums[i]; /*The other number of the pair should lie within the range 
			of currlower and currupper */
            int currupper=upper-nums[i];
            long x=bs1(nums,i+1,nums.length-1,currlower);  /*So we found the index of the element
			                                                 that is >= currlower */
            long y=bs2(nums,i+1,nums.length-1,currupper); /*So we found the index of the element 
			                                                that is <= currupper */
            cnt+=y-x+1;
        }
        return cnt;
    }
    public long bs1(int[] nums,int low,int high,int ele){
        long n=0;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]>=ele){
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return low;
    }
    public long bs2(int[] nums,int low,int high,int ele){
        long n=0;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]<=ele){
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return high;
    }
}