#include <bits/stdc++.h>

// Check the XOR approach.
// There is also an equation approach.
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int first,second;
	for(int i = 0;i<n;i++){
		if(arr[abs(arr[i]) - 1] > 0){
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		}
		else{
			first = abs(arr[i]);
		}
	}
	for(int i = 0;i<n;i++){
		if(arr[i] > 0){
			second = i + 1;
		}
	}
	return {second,first};


}
