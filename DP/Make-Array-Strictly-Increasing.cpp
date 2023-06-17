class Solution {
public:
    // Good dp problem.
      // Core logic is that when current is lesser than previous we must find a number in arr2 which is just greater than previous using upper bound.
      // When current is less than equal to previous we must either leave the number as it is (no operation) or we can do the uppor bound thing
      // The key here was the upper bound thing to be included in second case.
      
    int f(int i,int prev,vector<int>&arr1,vector<int>&arr2,vector<unordered_map<int,int>> &dp){
        if(i == arr1.size())return 0;
      
        // DP here stores the minimum number of operations till index i having previous as prev.
        if(dp[i][prev] > 0)return dp[i][prev];

        int leave = 1e9;
        int replace = 1e9;
        // Case 2 ignore part.
        if(arr1[i] > prev) leave = f(i + 1,arr1[i],arr1,arr2,dp);
        // Case 1 and 2 replace part.
        int rep = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();

        if(rep == arr2.size())replace = 1e9;
        else{
            replace = f(i + 1,arr2[rep],arr1,arr2,dp);
        }
        return dp[i][prev] = min(leave,replace + 1);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<unordered_map<int,int>> dp(2001); // DP declared like this so that it can accomodate negative indices and big values in general for prev part.
        int val = f(0,INT_MIN,arr1,arr2,dp);
        if(val != 1e9)return val;
        return -1;

    }
};
