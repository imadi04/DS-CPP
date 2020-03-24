/*
Given an integer array (of length n), find and return all the subsets of input array.
*/

#include <iostream>

using namespace std;

/***
You need to save all the subsets in the given 2D output array. 
And return the number of subsets(i.e. number of rows filled in output) 
from the given function.

In ith row of output array, 1st column contains length 
of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.

***/

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n==0)
         return 1;
       
    
    int temp=input[0];
    int size=subset(input+1,n-1,output);
    for(int i=size;i<2*size;i++){
        int j=output[i-size][0];
        while(j>=1){
            output[i][j+1]=output[i-size][j];
            j--;
        }
        output[i][1]=temp;
        output[i][0]=output[i-size][0]+1;
    }
    return 2*size;
}



int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
