/*
Given a string expression which consists only ‘}’ and ‘{‘. 
The expression may not be balanced. You need to find the minimum number 
of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
*/

#include <iostream>
using namespace std;
#include<stack>
int countBracketReversals(char input[]){
	// Write your code here
    int l;
    for(l=0;input[l]!='\0';l++);
    //cout<<l<<endl;
    if(l%2)
        return -1;
	
    
    int i=0;
    int count=0;
    stack<int>s;
    while(input[i]!='\0'){
        if(input[i]=='{'){
            s.push(input[i]);
           // i++;
            //continue;
        }
        else{
          	if(!s.empty() && s.top()=='{')
                s.pop();
            else
                s.push(input[i]);
        }
        i++;
    }
    while(!s.empty()){
        char a=s.top();
        s.pop();
        if(!s.empty()){
    	char b=s.top();
        s.pop();
            //cout<<a<<b;
            if(a==b)
            count++;
        else
            count+=2;
        }
       
        
    }
    //int n=s.size();
	//if(n%2==0 && n!=0)
        //return n/2;
    //cout<<count-1;
    return count;
}


int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}