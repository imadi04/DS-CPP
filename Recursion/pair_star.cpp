/*
Given a string, compute recursively a new string where identical chars 
that are adjacent in the original string are separated from each other by a "*".
*/


#include <iostream>
#include<string.h>
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.


void pairStar(char input[]) {
    int l=strlen(input)-1;
    // Write your code here
    while(l>=0){
        //int l=size(input)-1;
        if(input[0]==input[1]){
            input[l+2]='\0'; // don't forget to add null char at last of char array
            while(l>=1){     //otherwise it will generate error.
                input[l+1]=input[l];
                l--;
            }
            
            input[1]='*';
            pairStar(input+2);
        }
        else{
            pairStar(input+1);
        }
        
        break;
    }
}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
