#include <bits/stdc++.h>
// Simple sorting and checking adjacents.
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
