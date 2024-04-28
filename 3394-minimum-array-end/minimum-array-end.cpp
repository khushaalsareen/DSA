class Solution{ 
    public:
 long long addNum(int x){
        int temp = x;
        long long ans = 1;
        while(temp>0){
            ans = ans*2;
            temp /= 2;
        }
        return ans;
    }
    long long minEnd(int n, int x) {
        int num = x;
        int cnt = 0;
        do{
            if((num&x)==x){
                cnt++;
            }
            num++;
        }while((num&(num-1))>0);
        
        int extra = (n/cnt);
        int remaining = (n%cnt);
        if(remaining==0){
            extra--;
            remaining += cnt;
        }
        
        long long result = n;
        long long ans = x;
        int currcnt = 0;
        do{
            if((ans&x)==x){
                currcnt++;
                if(currcnt==remaining){
                    result = ans;
                    break;
                }
            }
            ans++;
            
        }while((ans&(ans-1))>0);
        
        string str = "";
        while(ans>0){
            if(ans%2!=0){
                str = str+'1';
                ans /= 2;
            }
            else{
                str = str+'0';
                ans /= 2;
            }
        }
        while(extra>0){
            if(extra%2!=0){
                str = str+'1';
                extra /= 2;
            }
            else{
                str = str+'0';
                extra /= 2;
            }
        }
        long long val = 0;
        long long curr = 1;
        for(int i = 0;i < str.size();i++){
            val += (str[i]-'0')*curr;
            curr = curr*2;
        }
        
        return val;
    }
};