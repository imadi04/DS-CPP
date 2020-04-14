#include <iostream>
using namespace std;
#include<stack>
bool checkBalanced(char *exp) {
	// Write your code here
    stack<char>s;
    bool flag=true;
	for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='('){
            s.push(exp[i]);
            continue;
        }
          
        if(s.empty())
            continue;//return true;
            
        else{
            char c=s.top();
            if(c=='(' && exp[i]==')' || c=='{' && exp[i]=='}' || c=='[' && exp[i]==']') {
                    // flag=true;
                s.pop();
         }
              //  else
                    //flag=false;
        }
    }
   // if(s.empty())
        //flag=true;
    return s.size()==0;
}
// Second approach
string isBalanced(string s) {
    stack<char> st;  
    
    for (auto c: s) {
        switch (c) {
            case '{':
            case '(':
            case '[':
                st.push(c);
                break;
            case '}':
                if (st.empty() || (st.top() != '{')) {
                    return "NO";
                }
                st.pop();
                break;
            case ')':
                if (st.empty() || (st.top() != '(')) {
                    return "NO";
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || (st.top() != '[')) {
                    return "NO";
                }
                st.pop();
                break;
        }
    }
    
    return st.empty() ? "YES" : "NO";

}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
