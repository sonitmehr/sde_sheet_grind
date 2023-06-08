#include <bits/stdc++.h>

// Alternate is Kadane's Algorithm,
long long findCrossSum(int arr[],int l,int r,int m){
    
    int left_sum = -1e9,right_sum = -1e9,sum = 0;
    for(int i = m;i>=l;i--){
        sum += arr[i];
        left_sum = max(left_sum,sum);
    }
    sum = 0;
    for(int i= m;i<=r;i++){
        sum += arr[i];
        right_sum = max(right_sum,sum);
    }

    return max(left_sum,max(right_sum,left_sum + right_sum - arr[m]));

}

long long f(int arr[],int l,int r){
    if(l > r)return -1e9;
    if(l == r)return arr[l];
    int m = (l + r)/2;

    return max(f(arr,l,m - 1),max(f(arr,m + 1,r),findCrossSum(arr,l,r,m)));
}

long long maxSubarraySum(int arr[], int n)
{
    return max(0LL,f(arr,0,n-1));

    
}
