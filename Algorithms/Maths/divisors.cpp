/*
Time complexity: O(sqrt(n))
Output: not Sorted
*/

#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int divisors(int n){
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(i==n){
				cout<<i<<" ";
			}
			else{
				cout<<i<<" "<<n/i<<" ";
				
			}
		}
	}
}


int main(){
	int n;
	cin>>n;
	divisors(n);
	
	return 0;
}
