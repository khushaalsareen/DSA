class Solution {
public:
    int f(int cnt1, int cnt2){
        int level = 1;
        while(true){
            if(level%2 == 1){
                if(cnt1<level)
                break;
                else{
                    cnt1-=level;
                    level++;
                }
            }
            else{
                if(cnt2<level)
                break;
                else{
                    cnt2-=level;
                    level++;
                }
            }
        }
        return level-1;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(f(red,blue),f(blue,red));
    }
};