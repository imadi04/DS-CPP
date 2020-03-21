/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
*/

#include <iostream>
#include<string.h>
using namespace std;

//approach 1:

void removeX(char s[]) {
	if (s[0] == '\0') {
		return;
	}

	if (s[0] != 'x') {
		removeX(s + 1);
	} else {
		int i = 1;
		for (; s[i] != '\0'; i++) {
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i]; //for appending null char in the last of string.
		removeX(s);
	}
}

//approach 2:
void removeX(char input[]) {
    // Write your code here
    while(*input!='\0'){
        int l=0;
        removeX(input+1);
        if(input[0]=='x'){
            while(input[l]!='\0'){
                input[l]=input[l+1];
                l++;
            }
        }
     break;   
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
