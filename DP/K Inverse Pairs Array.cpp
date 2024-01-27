// https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27
// TC : O(n*k)
// SC : O(n*k)
class Solution {
public:

    int dp[1001][1001];
    int mod = 1e9 + 7;
    int solve(int n,int k){
        if(n == 0)return 0;
        if(k == 0)return 1;

        if(dp[n][k] != -1)return dp[n][k];
        int count = 0;
        for(int i = 0;i<=min(n-1,k);i++){
             count = (count + solve(n - 1,k - i)) % mod;
        }
        return dp[n][k] = count;


    }

    int kInversePairs(int N, int K) {
        // memset(dp,0,sizeof(dp));
        // Tabulation but same time complexity
        // for(int n = 1;n<=N;n++){
        //     for(int k = 0;k<=K;k++){
        //         if(k==0){
        //             dp[n][k] = 1;
        //             continue;
        //         }

        //         for(int i = 0;i<=min(k,n-1);i++){
        //             dp[n][k] = (dp[n][k] + dp[n-1][k-i])%mod;
        //         }

        //     }
        // }
        // return dp[N][K];

        // Reducing time complexity
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1; // Important step here
        for(int n = 1;n<=N;n++){
            for(int k = 0;k<=K;k++){
                if(k == 0){
                    dp[n][k] = 1;
                    continue;
                }

                dp[n][k] = (dp[n - 1][k] + dp[n][k - 1]) % mod;
                if(k >= n){
                    dp[n][k] = (dp[n][k] - dp[n - 1][k - n] + mod) %mod;
                }
            }
        }
        return dp[N][K];



        // return solve(n,k);
    }
};
