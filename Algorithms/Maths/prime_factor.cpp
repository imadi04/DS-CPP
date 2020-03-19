/*
Program for prime factorization of a number

>>difference of two prime factors must be at least 2, this explains why i is incremented by 2.
>>Every composite number has at least one prime factor less than or equal to square root of itself.

Time complexity: O(sqrt(n))
it can be made better (O(log n)) using sieve , Do it later....
*/


#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int primefactor(int n){
	while(n%2==0){
		cout<<"2"<<" ";
		n/=2;
	}
	for(int i=3;i<=sqrt(n);i+=2){
		while(n%i==0){
			cout<<i<<" ";
			n/=i;
		}
	}
	
	if(n>2){
		cout<<n;
	}
}




int main(){
    int n;
    cin>>n;
    primefactor(n);
	return 0;
}




