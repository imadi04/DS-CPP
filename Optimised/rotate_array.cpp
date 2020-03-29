/*
Given a random integer array of size n, write a function that 
rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.

Sample Input :
7
1 2 3 4 5 6 7
2
Sample Output :
3 4 5 6 7 1 2

*/
#include <iostream>
using namespace std;

void Rotate(int arr[], int d, int size) {
    if(d>size)
        d=d-size;
    int *temp= new int[d];
    for(int i=0;i<d;i++)
        temp[i]=arr[i];
    for(int i=0;i<size-d;i++)
        arr[i]=arr[i+d];
    for(int i=size-d,j=0;i<size,j<d;i++,j++)
        arr[i]=temp[j];
}	


int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}
