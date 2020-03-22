#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int t;
    t=a;
    a=b;
    b=t;
}
int partition(int arr[],int low,int high){
    int x = arr[high];  
    int i = (low - 1);   
  
    for (int j = low; j <= high - 1; j++)  
    {  
        
        if (arr[j] < x)  
        {  
            i++;   
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}



void helper(int input[],int start,int end){
   if(start<end){
    int c=partition(input,start,end);
    helper(input,start,c-1);
    helper(input,c+1,end);
    }
}





void quickSort(int input[], int size) {
  if(size>0){
      int start=0;
    int end=size-1;
    helper(input,start,end);

  }
    
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


