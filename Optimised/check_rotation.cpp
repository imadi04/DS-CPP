/*
Given an integer array, which is sorted (in increasing order) and 
has been rotated by some number k in clockwise direction. 
Find and return the k.

Sample Input 1:
6
5 6 1 2 3 4
Sample Output 1:
2

*/
#include <iostream>
using namespace std;

int FindSortedArrayRotation(int arr[], int n) {
    int i=0;
    while(i<n){
        if(arr[i]>arr[i+1]){
            if(i+1==n)
                return 0;
            else
                return i+1;
        }
        i++;
    }
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindSortedArrayRotation(input,size);
	
	return 0;

}
