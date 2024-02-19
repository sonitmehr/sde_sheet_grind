// https://leetcode.com/problems/power-of-two/?envType=daily-question&envId=2024-02-19
// TC : O(1)
// SC : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long x = n;
        // Removing the last set bit.
        // (x & -x) will have the last set bit from left.
        // x - (x & -x) is us removing this last set bit 
        return x - (x & -x) == 0;
    }
};
