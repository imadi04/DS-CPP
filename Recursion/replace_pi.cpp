#include <iostream>
#include <string.h>
using namespace std;


int pow(int x, int n){
    int ans=1;
    while(n--)
        ans*=x;
    return ans;
}

int stringToNumber(char input[]) {
    
    // Write your code here
   while(*input!='\0'){
       int l=strlen(input);
       int ans=stringToNumber(input+1);
       //'1'-48=1; '2'-48=2 and so on..
       return ((input[0]-48)*pow(10,l-1))+ans;
       
   }
       
}





int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
