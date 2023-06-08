#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // [1,5][2,3]
  // Solved by self.
  // Have a look at the logic once more. Maybe got lucky.
    int n = intervals.size();
    if(n == 1)return intervals;
    sort(intervals.begin(),intervals.end());
    int prev = intervals[0][1];
    vector<vector<int>> ans;
    int first = intervals[0][0];
    for(int i = 1;i<n;i++){
        int a = intervals[i][0];
        int b = intervals[i][1];
        if(a <= prev){
            prev = max(b,prev);
        }
        else{
            ans.push_back({first,prev});
            first = a;
            prev = b;
        }
        if(i == n - 1){
            ans.push_back({first,prev});
        }
    }
    return ans;
}
