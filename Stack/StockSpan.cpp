#include <iostream>
using namespace std;
#include<stack>
int* stockSpan(int *price, int size) {
	// Write your code here
    int *arr=new int[size];
    stack<int>s;
    arr[0]=1;
    s.push(0);
    for(int i=1;i<size;i++){
       // int c=1;
        if(price[i]<price[s.top()]){
            arr[i]=i-s.top();
            s.push(i);
        }
        else{
            while((!s.empty()) && (price[i]>price[s.top()])){
                s.pop();
                //arr[i]=i
            }
            if(!s.empty())
                arr[i]=i-s.top();
            else
            	arr[i]=i+1;
            s.push(i);
        }
    }
	return arr;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}
