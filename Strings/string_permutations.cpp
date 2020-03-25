/*
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>

using namespace std;

int returnPermutations(string input, string output[]){
     if(input.length()==0){
       output[0]=""; 
        return 1;
    }
    int t=0;
    for(int i=0;i<input.length();i++){
        string temp=input.substr(0,i)+input.substr(i+1);
        char s=input[i];
        string output_temp[10000];
        int size=returnPermutations(temp,output_temp);
        for(int j=0;j<size;j++){
            output[t++]=s+output_temp[j];
        }
       
    }
     return t;
    
    
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
