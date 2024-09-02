class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        // count number of structurally unqiye BST with exactly i nodes
        for(int i = 2;i<=n;i++){
            // root of tree at j
            int sum  =0;
            for(int j = 1;j<=i;j++){
                int leftTrees = dp[j-1];
                int right = dp[i-j];
                sum+= leftTrees * right;
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};