#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int nl=m-l+1;
    int nr=r-m;
    int *left=new int[nl];
    int *right=new int [nr];
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
    delete [] left;
    delete [] right;
    
}

void helper(int input[],int start,int end){
    if(start<end){
        
        int mid=(start+end)/2;
        helper(input,start,mid);
        helper(input,mid+1,end);
        merge(input,start,mid,end);
    }
    
}

void mergeSort(int input[], int size){
	// Write your code here
    int start=0;
    int end=size-1;
    helper(input,start,end);   
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
