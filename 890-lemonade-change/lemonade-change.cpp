class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int n = bills.size();
       vector<int>nums = bills;
       int cnt = 0;
       sort(bills.begin(),bills.end());
       if(bills[0]!=5)
       return false;
       int five = 0, ten = 0;
       for(int i=0;i<n;i++){
        if(nums[i]==5)
        five++;
        else if(nums[i]==10){
            if(five == 0)
            return false;
            else
            {five--;
            ten++;
            }
        }
        else{
            if(ten>=1 && five>=1){
                ten--;
                five--;
            }
            else if(five>=3){
                five--;
                five--;
                five--;
            }
            else
            return false;
        }
       }
       return true; 
    }
};