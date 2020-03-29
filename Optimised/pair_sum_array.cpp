/*
Given a random integer array A and a number x. 
Find and print the pair of elements in the array which sum to x.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, 5) print "5 6". 
There is no constraint that out of 5 pairs which have to be printed in 1st line. 
You can print pairs in any order, just be careful about the order of elements in a pair.

Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x

Sample Input:
9
1 3 6 2 5 4 3 2 4
7
Sample Output :
1 6
3 4
3 4
2 5
2 5
3 4
3 4
*/
#include <iostream>
#include<algorithm>
using namespace std;


void pairSum(int input[], int size, int x) {
    sort(input,input+size);
    int i=0,j=size-1;
    while(i<j){
        if(input[i]+input[j]==x){
            int c=0;
             cout<<input[i]<<" "<<input[j]<<endl;
            while(input[j]==input[j-1] && i+1<j){
                j--;
                cout<<input[i]<<" "<<input[j]<<endl;
                c++;
            }
            j+=c;
            i++;
        }
        else if(input[i]+input[j]>x)
            j--;
        else{
            i++;
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
	pairSum(input,size,x);
		
	return 0;
}
