// C++ code to demonstrate the working of capacity(), resize() and shrink_to_fit() 
#include<iostream>
#include<string> 
using namespace std; 
int main() 
{ 
	string str = "Aditya's github."; 
	
	cout << "The initial string is : "; 
	cout << str << endl; 

	// Resizing string using resize() 
	str.resize(13); 

 
	cout << "The string after resize operation is : "; 
	cout << str << endl; 

	// Displaying capacity of string :It can be greater than or equal to size of string..
	cout << "The capacity of string is : "; 
	cout << str.capacity() << endl; 

 
	cout<<"The length of the string is :"<<str.length()<<endl; 

	// Decreasing the capacity of string using shrink_to_fit() 
	str.shrink_to_fit(); 

	cout << "The new capacity after shrinking is : "; 
	cout << str.capacity() << endl; 

	return 0; 

} 

