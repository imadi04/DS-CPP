/*
You are given a number N represented as a binary representation of X=16 bits. You are also given a number m and a character .
c(L or R).
Determine a number M that is generated after cyclically shifting the binary representation of N by  positions either left if c=L or right if is c=R.

Input format 

The first line contains an integer T representing the number of queries.
The next T lines contain N m c as mentioned in the problem statement.
Output format

Print T integers in a separate line representing the answer to each query.

Sample input: 			Sample Output:
2				55587				
7881 5 L			9177
7881 3 R
 
*/



#include <bits/stdc++.h>

using namespace std;

int main() {
	int num;
	cin >> num;
	for(int t=0;t<num;t++){
		 int n;
		 int m;
		char c;
		uint16_t ans;
		cin>>n>>m>>c;
		//m=m%16;
		//cout<<bitset<16>(n)<<endl;
		if(c=='L'){
			ans=(n << m)|(n >> (16 - m));
			cout<<ans<<endl;
		}
		if(c=='R'){
			ans=(n >> m)|(n << (16 - m));
			cout<<ans<<endl;
		}
	}										
	return 0;
}

