// C++ code to demonstrate the working of getline(), push_back() and pop_back() 
#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	string str; 
	char c;
	
	cout<<"Enter string:"<<endl;
	getline(cin,str); 

	cout << "The initial string is : "; 
	cout << str << endl; 
	
	cout<<"Enter character you want to push:"<<endl;
	cin>>c;
	str.push_back(c); 
	
	cout << "The string after push_back operation is : "; 
	cout << str << endl; 
	
	str.pop_back();
	cout << "The string after pop_back operation is : "; 
	cout << str << endl; 

	return 0; 

} 

