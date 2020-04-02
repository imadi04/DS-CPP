/*
Given a random integer array and a number x. 
Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
*/
#include <iostream>
using namespace std;
#include<algorithm>

void FindTriplet(int arr[], int size, int x) {
    sort(arr,arr+size);
   for(int i=0 ;i<size-2 ;i++)
   {
       for(int j=i+1 ;j<size-1 ;j++)
       {
           for(int k=j+1 ;k<size ;k++)
           {
               if(arr[i]+arr[j]+arr[k]==x)
               {
                   cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
               }
           }
       }
   }
}


int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}