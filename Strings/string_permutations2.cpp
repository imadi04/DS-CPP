#include <iostream>
#include <string>

using namespace std;

#include <string>
using namespace std;


void helper(string input,string output){
    
    if(input.length()==0){
       
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<input.length();i++){
        char c=input[i];
        string temp=input.substr(0,i)+input.substr(i+1);
        string op=c+output;
        helper(temp,op);
    }
}


void printPermutations(string input){
   helper(input,"");
}

int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
