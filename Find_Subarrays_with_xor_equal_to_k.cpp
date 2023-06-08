#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    // Very good logic here.
    // [a,b,c,d,e,f]
  //   [[y...][k.] ]
//     [[..xori..] ]
    
  // Find prefix xor. Now if prefix Xor == k then ans++;
  // Also check y = prefix_xor ^ k;
  // If we can find a prefix xor value as y then that means the remaining part of the array (also called sub array) has xor as k
    int n = arr.size();
    map<int,int> m;
    int xori = 0,ans = 0;
    for(int i = 0;i<n;i++){
        xori = xori ^ arr[i];
        int y = xori ^ k;
        ans += m[y];
        if(xori == k)ans++;
        m[xori]++;
    }
    return ans;

}
