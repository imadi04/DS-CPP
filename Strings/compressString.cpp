#include <iostream>
#include<cstring>
void stringCompression(char input[]) {
    // Write your code here
    char input2[1000];
    int j=0;
    int n = strlen(input); 
    for (int i = 0; i < n; i++) { 
  
        // Count occurrences of current character 
        int count = 1; 
        while (i < n - 1 && input[i] == input[i + 1]) { 
            count++; 
            i++; 
        } 
  
        input2[j]=input[i];
        j++;
        if(count>1){
          char c=count+48;
        input2[j]=c;
        j++;   
        }
       
        
    } 
    input2[j]='\0';
    int i=0;
    for(;input2[i]!='\0';i++){
        input[i]=input2[i];
    }
    input[i]='\0';

}
using namespace std;

int main() {
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}