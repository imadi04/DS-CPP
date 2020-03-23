/*
Given an integer n, using phone keypad find out and 
print all the possible strings that can be made using 
digits of input n.
Note : 
The order of strings are not important. 
Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>

using namespace std;

int keypad(int num, string output[]){
    if(num==1 || num==0){
        output[0]="";
        return 1;
    }
    else{
         int size=keypad(num/10,output);
       int digit=num%10;
        string alphas[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int alphasize[]={3,3,3,3,3,4,3,4};
        int i=0,j=0,c=0;
        string *temp=new string[size];
        for(int i=0;i<size;i++){
            temp[i]=output[i];
        }
       for(int i=0;i<alphasize[digit-2];i++){
          for(int j=0;j<size;j++){
                output[c]=temp[j]+alphas[digit-2][i];
                c++;    
          }
       }
        return alphasize[digit-2]*size;
    }
}



int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
