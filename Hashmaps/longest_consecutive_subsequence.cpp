#include <vector>
#include<unordered_set>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_set<int> S; 
    int count = 0; 
  	int res=0;
    // Hash all the array elements 
    for (int i = 0; i < n; i++) 
        S.insert(arr[i]); 
  
    // check each possible sequence from the start 
    // then update optimal length 
    for (int i=0; i<n; i++) 
    { 
        // if current element is the starting 
        // element of a sequence 
        if (S.find(arr[i]-1) == S.end()) 
        { 
            // Then check for next elements in the 
            // sequence 
            int j = arr[i]; 
            while (S.find(j) != S.end()) 
                j++; 
  
            // update  optimal length if this length 
            // is more 
           // count = max(count, j - arr[i]);
            if(count<j-arr[i]){
                count=j-arr[i];
                res=arr[i];
            }
                
        } 
    }
    vector<int>v;
    for(int i=res;i<res+count;i++)
        v.push_back(i);
    return v; 
}
#include<iostream>
using namespace std;

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}