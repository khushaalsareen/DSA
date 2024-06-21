class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
        return 1;
        if(n==2){
            if(arr[0]!=arr[1])
            return 2;
            else
            return 1;
        }
        int j = 2;
        bool flag = true; // assuming increasing ie arr[0]<arr[1]
        if(arr[0]>arr[1])
        flag = false; // decreasing trend
        int cl = 1;
        if(arr[0]!=arr[1])
        cl++;
        int ml = cl;
        while(j<n){
            if(arr[j]>arr[j-1]){
                if(flag)
                cl = 2;
                else
                cl++;
                flag = true; // denotes last updated trend
            }
            else if(arr[j]<arr[j-1]){
                if(flag)
                cl++;
                else
                cl = 2;
                flag = false;
            }
            else{
                cl = 1;
            }
            ml = max(ml,cl);
            j++;
    }
    return ml;
    }
};