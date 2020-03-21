#include <iostream>
#include <string.h>
using namespace std;


void replacePi(char input[]) {
    
	// Wr(ite your code here
    while(*input!='\0'){
        
        if(input[0]=='p' && input[1]=='i'){
            replacePi(input+2);
            int l=strlen(input)-1;
            while(l>=2){
                input[l+2]=input[l];
                l--;
            }
                
            input[0]='3';
            input[1]='.';
            input[2]='1';
            input[3]='4';   
        
        }
        else{
            replacePi(input+1);
        }
       break;
    }
}



int main() {
     char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
