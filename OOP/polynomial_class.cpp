#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
    public :
    int *degCoeff;      
    int capacity;
   
    Polynomial(){
   degCoeff = new int[10];       
         capacity = 10;
        for(int i =0; i<capacity;++i){
           degCoeff[i] = 0;
        }
    }
    Polynomial(Polynomial const &s2){
        degCoeff = new int[s2.capacity];
        for(int i =0; i<s2.capacity; ++i){
        degCoeff[i] = s2.degCoeff[i];
        }  
        capacity = s2.capacity;
    }
      void operator=(Polynomial const &s2){
           delete [] degCoeff; // delete keyword does not delete pointer
          // it just dealloactes the memory pointed by the pointer
          degCoeff = new int[s2.capacity];
        for(int i =0; i<s2.capacity; ++i){
        degCoeff[i] = s2.degCoeff[i];
        }  
        capacity = s2.capacity;
    }
   void setCoefficient(int degree, int coeff){
       int size =capacity;
       
       if(degree>=capacity){
            size = 2*capacity;
           while(size<=degree){
               size = 2*size;
           }
       }
       int *newdegCoeff = new int[size];
       for(int i =0; i<size;++i){
           newdegCoeff[i] = 0;
       }
   
      for(int i =0; i<capacity;++i){
           newdegCoeff[i] = degCoeff[i];
       }
   
   
capacity = size;
delete [] degCoeff;
degCoeff = newdegCoeff;
 degCoeff[degree] = coeff;}
   
void print(){
    for(int i = 0; i<capacity; ++i){
        if(degCoeff[i] != 0){
            cout<<degCoeff[i]<<"x"<<i<<" ";
        }
    }
    cout<<endl;
}
Polynomial operator+(Polynomial const &s2){
    Polynomial result;
    int i =0; int j =0;
    while(i<capacity && j<s2.capacity){
        int deg = i;
        int coeff = degCoeff[i] + s2.degCoeff[i];
        result.setCoefficient(deg,coeff);
        ++i;
        ++j;
    }
    while(i<capacity){
           result.setCoefficient(i,degCoeff[i]);
            ++i;
        }
    while(j<s2.capacity){
        result.setCoefficient(j,s2.degCoeff[j]);
        ++j;
    }
    return result;
}
Polynomial operator-(Polynomial const &s2){
    Polynomial result;
    int i =0; int j =0;
    while(i<capacity && j<s2.capacity){
        int deg = i;
        int coeff = degCoeff[i] - s2.degCoeff[i];
        result.setCoefficient(deg,coeff);
        ++i;
        ++j;
    }
    while(i<capacity){
           result.setCoefficient(i,degCoeff[i]);
            ++i;
        }
    while(j<s2.capacity){
        result.setCoefficient(j,(-1*s2.degCoeff[j]));
        ++j; 
    }
    return result;  
}

int getCoefficient(int degree){
    if(degree>=capacity){
        return 0;
    }
    else{
        return degCoeff[degree];
    }
}
Polynomial operator*(Polynomial s2){
    Polynomial result;
    for(int j=0; j< s2.capacity; ++j){
        for(int i=0; i<capacity;++i){
            int deg = i+j;
            int coeff = result.getCoefficient(deg) + (degCoeff[i]* s2.degCoeff[j]);
            result.setCoefficient(deg,coeff);
        }
    }
    return result;
}
};



//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
