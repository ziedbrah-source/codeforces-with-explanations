
using namespace std;
#include<bits/stdc++.h>

// we have k-1 splitters with 2...k outputs and one input, we want a pipe with n outputs, with every pipe , just one splitter can go with it.
// test cases: n=4,k=3 -> we have 2 splitters , one with 2 outputs, the other with 3 outputs, or 4=2-1+3-1 , the "-1" cause when we use a splitter we lose an output.
// n=5 k=5, we need one splitter :) ..
// sum 1->k = k*(k+1)/2 
// sum k->n = n*(n+1)/2- (k-1)*(k)/2
// We said that with every use of splitter we lose an output, -> we can transform the problem to be easier.
// lets say n=37, k=11
// most we can make of outputs is: 2+3-1+4-1+5-1+6-1+7-1+8-1+9-1+10-1+11-1=2+3+4+5+6+7+8+9+10+11-(9)
// but if we do 2-1+3-1+4-1+....+11-1 = then we get 1--->k-1 , 
// so we also make N=N-1 (because we added that -1 from the first "2-1" )
// so we can make all the combinations, but complexity will be , O(k^2) if we brute force it 
// we have k-1 splitters: 2,3,4,5,...,k outputs, we need to get the least needed number of splitters wich we get N "the N-1)
// so we use biary search to see the sum from half to k , if >n , we go to the right by one, if equal then we have the solution (end-half+1) if <n then we return end -half +2 
// +2 is : end -start +1 +1 "the last "1" is the fact we have 2-->k , so if we have <n and we are using binary search, so we are sure that we have the missed value in the other part .



long long sum(long long k){
	return k*(k+1)/2;
}

long long sumFromTo(long long k,long long n ){
	if(k<1){
		return sum(n);
	}
	return sum(n)-sum(k-1);
}


long long minSplitters(long long n,long long k){
	long long st=1;
	long long end=k;
	while(st<end){
		long long mid=(st+end)/2;
		long long sm=sumFromTo(mid,k);
		if(sm==n){
			return k-mid+1;
		}
		if(sm>n){
			st=mid+1;
		}else { // sm < n 
			end=mid; 
		}
	}
	return k-st+2;
}


int main()
{
	long long k;
	long long n;
	cin >> n >> k;
	
	if(n==1){
		cout << 0 << endl;
		return 0;
	}
	if(n<=k){
		cout << 1 << endl;
		return 0;
	}else {
		n--;
		k--;
		if(sum(k)<n){
			cout << -1 << endl;
			return 0;
		}else{
			// there is a solution
			cout << minSplitters(n,k);
		}
	}

      

    return 0;
}
