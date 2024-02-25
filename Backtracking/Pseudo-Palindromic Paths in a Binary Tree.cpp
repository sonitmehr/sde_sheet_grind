// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
// TC : O(n) 
// SC : O(h) [Recursive stack space]
// BitMasking approach
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, int result) {
        if (root == NULL)
            return;
        int val = root->val;
      // Storing the frequency as a bitmask.
      // Even is 0 and odd is 1.
        int newFrequency = result ^ (1 << val);
    
        if (root->left == NULL && root->right == NULL) {
          // The result stores frequency of each value (1 - 9). So we expect result to have either 0 or 1 set bits.
          // Hence we do n*n-1 operation as for 1 set bit it will always be 0
            if ((newFrequency & (newFrequency - 1)) == 0) { // I used n & -n as that can either be 0 or n for checking 1 set bit ⚠️⚠️⚠️
                ans++;
            }
        }
        solve(root->left, newFrequency);
        solve(root->right, newFrequency);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};
