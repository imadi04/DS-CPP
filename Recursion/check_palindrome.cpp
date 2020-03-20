/*
Check if a given String S is palindrome or not (using recursion).
 Return true or false.
 Only string is passed as parameter.
*/
#include <iostream>
#include<string.h>
using namespace std;
bool helper(char input[],int start,int end){
    if(start>end)
        return 1;
    if(input[start]!=input[end]){
        return 0;
    }
    else if(input[start]==input[end]){
        bool ans=helper(input,start+1,end-1);
        return ans;
    }
}

bool checkPalindrome(char input[]) {
        int start=0;
        int end=strlen(input)-1;
        return helper(input,start,end);  
}





int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
