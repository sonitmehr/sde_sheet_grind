// https://leetcode.com/contest/weekly-contest-381/problems/count-the-number-of-houses-at-a-certain-distance-i/


class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> ans(n,0);
        if(x > y){
            swap(x,y);
          // x needs to come before y
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
              // We are only checking our left side. 
              // Means i is curr pos and j is where we want to reach
                int ind = i - j;
                ind =min(ind,abs(j - x) + abs(i - y) + 1); // Check if going directly i -> j is cheaper or through the extra path
                ans[ind-1] += 2;
            }
        }
        return ans;
        
    }
}; 
