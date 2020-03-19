/*
Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.

Do this recursively. Indexing in the array starts from 0.
*/

#include<iostream>
using namespace std;

//method 1: traversing array from 0 to (N - 1).
int lastIndex1(int input[], int size, int x) {
    if(size==0)
        return -1;
    else{
        int ans=lastIndex1(input+1,size-1,x);
        if(ans==-1){
            if(input[0]==x)
                return 0;
            else
                return -1;
        }
        else
            return ans+1;
    }

}

//method 2: traversing array from (N - 1) to 0. This is prefered way.
int lastIndex(int input[], int size, int x) {
    if(size==0)
        return -1;
    if(input[size-1]==x)
        return size-1;
    else{
        int ans=lastIndex(input,size-1,x);
        return ans;
    }
}



int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


