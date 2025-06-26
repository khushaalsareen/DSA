class Solution {
public:
    int maximumSwap(int num) {
        string str = "";
        int tmp = num;
        if(num==0)
        return 0;
        while(tmp>0){
            int digit = tmp%10;
            str+=to_string(digit);
            tmp/=10;
        }
        reverse(str.begin(),str.end());
        int n = str.size();
        vector<pair<int,int>>smax(n); //{idx,num}
        
        smax[n-1] = {n-1,str[n-1]-'0'};
        
        for(int i=n-2;i>=0;i--){
            int currNum = str[i] - '0';
            int nxtMax = smax[i+1].second;
            int nxtMaxIdx = smax[i+1].first;
            if(nxtMax>=currNum){
                smax[i] = {nxtMaxIdx,nxtMax};
            }
            else{
                smax[i] = {i,currNum};
            }
        }

        for(int i=0;i<n-1;i++){
            int currNum = str[i]-'0';
            int nxtMax = smax[i+1].second;
            int nxtMaxIdx = smax[i+1].first;
             if(nxtMax> str[i]-'0'){
                swap(str[i],str[smax[i+1].first]);
                break;
            }
        }

     
        return stoi(str);
    }
};