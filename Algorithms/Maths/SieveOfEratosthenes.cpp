/*
To find all prime numbers less than n
*/

#include<conio.h>
#include<math.h>
#include<iostream>
using namespace std;

int SieveOfEratosthenes(int n){
	bool *prime=new bool[n+1];
	memset(prime,true,sizeof(prime));
	
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=p*p;i<=n;i+=p){
				prime[i]=false;
			}
		}
	}
	for(int p=2;p<=n;p++){
		if(prime[p]){
			cout<<p<<" ";
		}
	}
}

int main(){
	int n;
	cin>>n;
	SieveOfEratosthenes(n);
	return 0;
}
