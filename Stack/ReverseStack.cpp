#include <iostream>
using namespace std;
#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
	if(input.size()<=1)
        return;
    int start=input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        int t=input.top();
        input.pop();
        extra.push(t);
    }
    input.push(start);
    while(!extra.empty()){
        int t=extra.top();
        extra.pop();
        input.push(t);
    }
}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
