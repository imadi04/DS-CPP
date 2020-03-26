/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include<iostream>
#include <string>
using namespace std;

int getCodes(string input, string output[10000]) {
    if(input.length()==0){
        output[0]="";
        return 1;
    }
        
    int t=0;
    string one[10000];
    string two[10000];
    int ch=input[0]-'0';
    string te=input.substr(0,2);
    int ch2=stoi(te);
    int s1=getCodes(input.substr(1),one);
    int s2;
    
         
    for(int i=0;i<s1;i++){
        char x=(ch-1+'a');
        output[t++]=x+one[i];
    }
    if(ch2>=11 && ch2<=26){
        s2=getCodes(input.substr(2),two);
        for(int j=0;j<s2;j++){
        char y=(ch2-1+'a');
        output[t++]=y+two[j];
        
        }
    }
    
    return t;
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
