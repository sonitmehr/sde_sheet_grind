// https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04
// TC : O(n + m) size of s + size of t
// SC : O(26)


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmap;
        // Make a t_map for elements in t
        for(auto &c : t)tmap[c]++;
    
        int minLength = 1e9,minStart = -1;
        int i=0,j = 0,n=s.size(),counter = t.size();
        
        // Simple 2 pointer sliding window
        while(j < n){
            // Keep increasing window until counter is 0
            // When counter is 0 it means we have all elements of t in window

            if(tmap[s[j]] > 0){
                counter--;
            }
            tmap[s[j]]--;
            
            while(counter == 0){
                // Now minimize the window by increasing i
                // Set the variables to length of window
                if(j - i + 1 < minLength){
                    minLength = j - i + 1;
                    minStart = i;
                }
                
                tmap[s[i]]++;
                // Increase counter if any element of t is removed from window.
                if(tmap[s[i]] > 0){
                    counter++;
                }
                i++;
            }
            j++;

        }

        return (minLength == 1e9) ? "" : s.substr(minStart,minLength);
    }
};
