#include <iostream>
#include<string>
using namespace std;

#include <string.h>
using namespace std;

void helper(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
     int t=0;
    string one;
    string two;
    int ch=input[0]-'0';
    char x=(ch-1+'a');
    string te=input.substr(0,2);
    int ch2=stoi(te);
    one=output+x;
    helper(input.substr(1),one);
   
    if(ch2>=11 && ch2<=26){
        char y=(ch2-1+'a');
        two=output+y;
        helper(input.substr(2),two);
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    helper(input,"");
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
