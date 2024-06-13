class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
        return a.second<b.second;
        return a.first<b.first;
    }
    int f(int i,int prev,vector<pair<int,int>> &v,vector<vector<int>> &dp)
    {
        if(i>=v.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int pick=INT_MIN;
if(prev==-1 or (v[i].first>v[prev].first and v[i].second>=v[prev].second) or (v[i].first==v[prev].first) or (v[i].first<v[prev].first and v[i].second<v[prev].second))//pick condition
        {
            pick=v[i].second+f(i+1,i,v,dp);//pick only if 
			//1.age of current index greater than age of previous and also scores[i]>=scores of previous index
			//2.age of current index player equal to age of previous index player
			//3.age of current index player less than age of previous index player and also score of current index player less than score of previous index player
        }
        int notpick=f(i+1,prev,v,dp);
        return dp[i][prev+1]=max(pick,notpick);//returning maximum of pick and notpick
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end(),cmp);//sorting according to the ages
        return f(0,-1,v,dp);
    }
};