/*
Given two random integer arrays, print their intersection. 
That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


void intersection(int input1[], int input2[], int size1, int size2) {
    sort(input1,input1+size1);
    sort(input2,input2+size2);
    int i=0;
    int j=0;
    if(size1>size2){
        while(j<size2){
        if(input1[i]==input2[j]){
            cout<<input1[i]<<endl;
            i++;
            j++;
        }
        else if(input1[i]<input2[j])
            i++;
        else
            j++;
        }
    }
    else{
        while(i<size1){
          if(input2[j]==input1[i]){
            cout<<input2[j]<<endl;
            i++;
            j++;
        }
        else if(input2[j]<input1[i])
            j++;
        else
            i++;  
        }
    }
}


int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}
