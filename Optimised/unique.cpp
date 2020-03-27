#include<iostream>
#include <algorithm>
using namespace std;

// arr - input array
// size - size of array

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ans=0;
    for(int i=0;i<size;i++)
        ans^=arr[i];
    return ans;
}

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindUnique(input,size)<<endl;
		
	return 0;
}
