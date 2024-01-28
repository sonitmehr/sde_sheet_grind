// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28
// TC : O(row * col * col)
// SC : O(row)

// Easy prefix sum logic but i would say re watch the video to revise all approaches  
// https://www.youtube.com/watch?v=xaL5rO_o7kw
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        for (int row = 0; row < n; row++) {
            for (int col = 1; col < m; col++) {
                mat[row][col] += mat[row][col - 1];
            }
        }
        /*
        [[ 1,  1, 1],
         [-1, -1, 1],
         [ 1,  1,-1]],


        */
        unordered_map<int, int> mp;
        int ans = 0;
        for (int colStart = 0; colStart < m; colStart++) {
            for (int colEnd = colStart; colEnd < m; colEnd++) {
                mp.clear();
                mp[0] = 1;
                int currSum = 0;
                for (int i = 0; i < n;i ++){
                    currSum += mat[i][colEnd] - (colStart ? mat[i][colStart - 1] : 0);
                    ans += mp[currSum - target];
                    mp[currSum] ++;
                }
            }
        }
        return ans;
    }
};
