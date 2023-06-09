int modularExponentiation(int v, int n, int m) {
	 // Logic is good.
  // If power is even like 2^10 then write it as 4^5
  // Now power on 4 is odd, send one 4 to ans;
  // So ans is 4 and remaining is 4^4
  // Write it as 16^2 and then 256^1
  // Now ans is 4 * 256 % mod
	long long prod = 1;
	long long x =v;
	x = x % m;
	if(x == 0)return 0;

	while(n > 0){
		if(n%2 == 1){
			prod = prod*x % m;
		}

		x = ((long long)(x*x)) % m;
		n /= 2;
	}
	return prod;


}
