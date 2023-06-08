#include <bits/stdc++.h> 
int dp[101][101];
bool check(int i,int j,int n,int m){
	if(i < 0 || j < 0 || i >=n || j >= m)return false;
	return true;
}

int f(int i,int j,int n,int m){
	if(check(i,j,n,m) == false)return 0;
	if(i == n - 1 && j == m -1)return 1;

	if(dp[i][j] != -1)return dp[i][j];
	return dp[i][j] = f(i + 1,j,n,m) + f(i,j + 1,n,m);
	
	


}

int uniquePaths(int n, int m) {
	// Write your code here.
	memset(dp,-1,sizeof(dp));
	return f(0,0,n,m);
}
