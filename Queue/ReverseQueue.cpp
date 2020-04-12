#include <iostream>
using namespace std;
#include <queue>
#include<stack>
void reverseQueue(queue<int> &q) {
	// Write your code here
	int n=q.size();
    stack<int>s;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        s.push(t);
    }
    while(!s.empty()){
        int t=s.top();
        s.pop();
        q.push(t);
    }
}

int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}
