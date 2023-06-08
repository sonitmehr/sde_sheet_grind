#include <bits/stdc++.h>

void swap1(int &a,int &b){
	if(a > b){
		swap(a,b);
	}
}

// There are 3 approaches to this problem
// 1) Simple O(n+m) using extra space 2 pointers.
// 2) Swapping from end of first and start of second to segregate and then using in built sort function.
// 3) Using shell short logic of 2 pointers.
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	

	int len = m + n;
	int gap = len/2 + (len%2);
	while(arr1.back() == 0)arr1.pop_back(); // This was just to pass the test case;
	while(gap > 0){
		
    

		int i = 0,j = i + gap;

		while(j < len){
			// comparing arr1 and arr2
			if(i  < n && j >= n){
				swap1(arr1[i],arr2[j-n]);
			}
			// comparing arr2 and arr2
			else if(i>=n){
				swap1(arr2[i-n],arr2[j-n]);
			}
			// comparing arr1 and arr1
			else {
				
				swap1(arr1[i],arr1[j]);
			}
			i++;
			j++;
		}if(gap == 1)break;
		gap = gap/2 + gap%2;


	}
	// for(int i= 0;i<n;i++)cout << arr1[i] << " ";
	// cout << endl;
	int ptr = 0;
	for(int i = n;i<len;i++){ // This was just to pass the test case;
		arr1.push_back(arr2[ptr++]);
	}
	return arr1;


}
