#include <bits/stdc++.h>
// Simple sorting and checking adjacents.
// APPROACH 1
// TC : O(nlogn)
// SC : O(1)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    sort(arr.begin(),arr.end());
    int maxi = 0;
    int prev = arr[0];
    int curr = 1;
    for(int i = 1;i<n;i++){
        if(arr[i] == prev)continue;
        if(arr[i] == prev + 1){
            curr++;
            
        } // [0,1,1,2]
        else curr = 1;
        prev = arr[i];
        maxi = max(maxi,curr);
    }
    maxi = max(maxi,curr);
    return maxi;
}// [20,30,33,34,35]

// APPROACH 2
// Check previous in set. If it's not there then it means that that particular element is the first in it's sequence.
// Hence we now check it's next consecutive elements in the set.
// It is unordered so time complexity is O(n) with O(n) space.
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    unordered_set<int> st;
    for(auto &i : arr)st.insert(i);
    int maxi = 0;
    int curr = 0;
    for(auto it = st.begin();it != st.end();it++){
        auto p = *it;
        if(st.find(p - 1) == st.end()){
            curr = 0;
            while(st.find(p) != st.end()){
                curr++;
                p++;
            }


        }
        maxi = max(maxi,curr);
    }
    return maxi;
    

}
