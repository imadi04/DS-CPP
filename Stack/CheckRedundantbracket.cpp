#include <iostream>
using namespace std;
#include<stack>
#include<string>
bool checkRedundantBrackets(char *input) {
    bool flag=false;
	// Write your code here
    stack<char>s;
   // int l=strlen(input);
    for(int i=0;input[i]!='\0';i++){
        if(input[i]!=')'){
            s.push(input[i]);
            continue;
        }
        int count=0;
        while(true){
            char a=s.top();
            if(a=='('){
                s.pop();
                break;
            }
               // break;
            count++;
            s.pop();
        }
        if(!count)
            return true;
        else
            flag=false;
        
    }
    return flag;

}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
