// https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
// TC : O(n + klogk)
// SC : O(n)

// There is a bucket sort (counting sort) approach as well. But that seemed less efficient
 class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> freq;
        for (auto& c : s)
            freq[c]++;
        string ans;

        vector<pair<int, char>> vec;
      // This solution is just taking frequency, putting in vector of pair then sorting
      // just like we do in cp
        for (auto& i : freq) {
            vec.push_back({i.second,i.first});
        }
        sort(vec.rbegin(),vec.rend());
        for (auto& i : vec) {
            while (i.first--) {
                ans += i.second;
            }
        }
        return ans;
    }
};
