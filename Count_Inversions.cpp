#include <bits/stdc++.h> 

// This is the merge sort logic. Just add inversion count when lhs is greater than rhs while merging.

int temp[100001];
// long long ans = 0;
long long merge(long long *arr,int n,int l,int m,int r){

    int i = l,j = m;
    long long ptr = 0,ans = 0;
    while(i < m && j <= r){
        if(arr[i] <= arr[j]){
            temp[ptr] = arr[i];
            i++;
        }
        else{
            temp[ptr] = arr[j];
            j++;
            ans += m - i; 
        }
        ptr++;
    }

    while(i < m){
        temp[ptr++] = arr[i];
        i++;
    }
    while(j <= r){
        temp[ptr++] = arr[j];
            j++;
    }
    ptr = 0;
    for(int i = l;i<=r;i++){
        arr[i] = temp[ptr++];
    }
    return ans;
}

long long mergeSort(long long *arr,int n,int l,int r){
    if(l >= r)return 0;
    long long ans = 0;
    int m = (l + r)/2;

    
    ans += mergeSort(arr,n,l,m);
    ans += mergeSort(arr,n,m + 1,r);
    ans += merge(arr,n,l,m + 1,r);
    return ans;


}


long long getInversions(long long *arr, int n){
    // ans = 0;

    int ans = mergeSort(arr,n,0,n-1);
    // for(int i= 0;i<n;i++)cout << arr[i] << " ";
    return ans;

    // return ans;

}
