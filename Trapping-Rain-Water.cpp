#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // So remember the prefix and suffix max array approach.
   // So we enter into left when it is smaller than right.
  // Only add to sum when left mein merse bada tower hai, because I know ki right mein toh hai.
  // Enter right when smaller then left.
  // Only add when right mein merse bada tower hai, because I know ki left mein toh hai.
    int l = 0,r = n - 1;
    long sum = 0;
    long leftMax = 0,rightMax = 0;
    while(l < r){
        if(arr[l] <= arr[r]){
            if(arr[l] >= leftMax)leftMax = arr[l];
            else sum += (leftMax - arr[l]);
            l++;
        }
        else{
            if(arr[r] >= rightMax) rightMax = arr[r];
            else sum += (rightMax - arr[r]);
            r--;
        }
    }
    return sum;
}
