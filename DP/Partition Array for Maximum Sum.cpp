
// https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03
// TC : O(n*k)
// SC : O(n)
// See O(k) approach

class Solution {
public:
    int dp[501];
    int solve(int i,vector<int> &arr,int k){
        if(i >= arr.size())return 0;

        if(dp[i] != -1 )return dp[i];

        int maxi = 0,ans = 0;

      // Make arrays of all sizes from 1 to k
        for(int j = i;j<arr.size() && j < (i + k);j ++){
            maxi = max(maxi,arr[j]);
            // get maxi throughout the subarray and add it to answer
            ans = max(ans, maxi * (j - i + 1) + solve(j + 1,arr,k));
        }
        return dp[i] = ans;
        


    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
       return solve(0,arr,k);
    }
};

// TABULATION APPROACH


class Solution {
public:
    

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       
        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i = n - 1;i>=0;i--){
            int maxi = 0,ans = 0;
            for(int j = i;j<(i + k) && j < n;j ++) {
                maxi = max(maxi,arr[j]);
                ans = max(ans, maxi * (j - i + 1) + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];

    }
};
