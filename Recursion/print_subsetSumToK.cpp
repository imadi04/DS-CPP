#include <iostream>
using namespace std;

void helper(int input[],int size,int k,int output[],int m){
    if(size==0){
        if(k==0){
            for(int i=0;i<m;i++){
                 cout<<output[i]<<" ";
            }
            cout<<endl;
            return;   
        }
        else
            return;
    }
    
    int t=input[0];
    int *temp=new int[m+1];
    for(int i=0;i<m;i++)
        temp[i]=output[i];
    temp[m]=input[0];
    helper(input+1,size-1,k-t,temp,m+1);
    helper(input+1,size-1,k,output,m);
}


void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int *output=new int[size];
    int m=0;
    helper(input,size,k,output,m);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
