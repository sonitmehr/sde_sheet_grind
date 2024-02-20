// https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08
// TC : O(n* root(n))
// SC : O(n)

class Solution {
public:
    int dp[10001];
    int solve(int n){
        if(n <= 0) return 0;
        int ans = 1e9;
        if(dp[n] != -1)return dp[n];

        // Check all different possibilities for square root.
        for(int i = 1;i*i <= n;i ++){
            ans = min(ans,1 + solve(n - i*i));
        }

        return dp[n] = ans;
    }


    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
