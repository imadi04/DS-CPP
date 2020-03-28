/*
Given two random integer arrays, print their intersection. 
That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int nl=m-l+1;
    int nr=r-m;
    int *left=new int[nl];
    int *right=new int[nr];
   // int all[r+1];
    for(int i=0;i<nl;i++)
        left[i]=arr[l+i];
     for(int i=0;i<nr;i++)
        right[i]=arr[m+1+i];
    int i=0;
    int j=0;
    int k=l;
    while(i<nl && j<nr){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=right[j];
        j++;
        k++;
    }
    
}

void mergesort(int input[],int start,int end){
    if(start<end){
        
        int mid=(start+end)/2;
        mergesort(input,start,mid);
        mergesort(input,mid+1,end);
        merge(input,start,mid,end);
    }
    
}
void intersection(int input1[], int input2[], int size1, int size2) {
    mergesort(input1,0,size1-1);
    mergesort(input2,0,size2-1);
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
