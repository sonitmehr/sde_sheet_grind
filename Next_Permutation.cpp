#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &v, int n)
{
    int ind = -1;
  // Find breakpoint.
  // Break point is the point where the increasing array suddenly drops when looking from the back.
    for(int i = n - 2;i>= 0;i--){
        if(v[i] < v[i + 1]){
            ind = i;
            break;
        }
    }
  // If it's the last permutation then ind stays -1
    if(ind == -1){
        reverse(v.begin(),v.end());
        return v;
    }
    // Swap the break point element with the element that is just greater.
    for(int i = n - 1;i>=ind;i--){
        if(v[i] > v[ind]){
            swap(v[i],v[ind]);
            break;
        }
    }
  // Reverse the right side of breakpoint.
    reverse(v.begin() + ind + 1,v.end());
    return v;

}
