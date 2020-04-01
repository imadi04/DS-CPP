/*
A word or a sentence is called a pangram if all the characters 
of this language appear in it at least once. You are given a 
string s consisting of lowercase and uppercase Latin letters. 
Check whether this string is a pangram. Print "YES" or "NO".
*/
#include<iostream>
#include<vector>
using namespace std;
void ans (int n, string S)
{	if(n<26){
    cout<<"NO";
    exit(0);
}
    // Write your code here
    vector<bool>mark(26,false);
    int index;
    for(int i=0;i<n;i++){
        if(S[i]>='A' && S[i]<='Z')
            index=S[i]-'A';
        else if(S[i]>='a' && S[i]<='z')
            index=S[i]-'a';
        else
            continue;
        mark[index]=true;
    }
    bool flag;
    for(int i=0;i<26;i++){
         if(!mark[i]){
             flag=false;
             break;
         }
        else
            flag=true;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
       
    
}