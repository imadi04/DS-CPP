/*
Given 3 Strings, check whether the 3rd string contains 
all the characters of string 1 and 2 in any order. 
If all the characters are present, print "YES" otherwise print "NO".
There should not be any extra character and any missing character.
The string s contains uppercase Latin letters only.
*/

//Approach 1:
#include<iostream>
#include<algorithm>
using namespace std;

void answer(string s1,string s2,string s)
{
	string t=s1+s2;
    //cout<<t<<endl;
    sort(t.begin(),t.end());
    sort(s.begin(),s.end());
   // cout<<t<<endl;
    if((s.compare(t))==0)
        cout<<"YES";
    else
        cout<<"NO";
    return;
}
//Approach 2:
#include <cstdlib> 
int S1[256],S2[256],S[256]; 
void answer(string s1,string s2,string s) 
{
    memset(S1,0,sizeof S1);
    memset(S2,0,sizeof S2);
    memset(S,0,sizeof S); 
    for (int i=0;i<s1.size();i++) 
        S1[s1[i]]++; 
    for (int i=0;i<s2.size();i++) 
        S2[s2[i]]++;
    for (int i=0;i<s.size();i++) 
        S[s[i]]++; 
    for (int i=0;i<256;i++) 
    { 
        if (S[i]!=S1[i]+S2[i]){
            cout<<"NO"<<endl;
            exit(0);
        }     
        cout<<"YES"<<endl; 
    }
    return ; 
}