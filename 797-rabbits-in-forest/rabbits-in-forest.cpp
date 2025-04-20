class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int coverTill = -1;
        int ind = 0;
        int n = answers.size();
        int cnt = 0;
        while(ind<n){
            int val = answers[ind];
            if(ind>0 && val == answers[ind-1] && ind<=coverTill){
                ind++;
            }
            else{
                cnt+=(val+1);
                coverTill = ind + val ;
                ind++;
            }
        }
        return cnt;
    }
};