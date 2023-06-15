#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    // So I saw striver video here. Basically 2 pointers + map.
  // Update l to last occurence of r to check for the next continuous sequence.
    unordered_map<char,int> m;
    int maxi = 0;
    int curr = 0;
    int r = 0,l = 0;
    int n = s.size();
    // for(auto &i : s)m[i] =
    for(int i= 0;i<n;i++){
      

        if(m.find(s[i]) != m.end())l = max(m[s[i]] + 1,l); // This line is important to remember.
        m[s[i]] = i;
      
      maxi = max(maxi,i-l + 1);
    }
    return maxi;

}
