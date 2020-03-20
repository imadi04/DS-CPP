/*
Given an integer n, count and return the number of zeros 
that are present in the given integer using recursion.
*/

#include <iostream>
using namespace std;


int countZeros(int n) {
    // Write your code here
    if(n<=0)
        return 0;
    else{
        int ans=countZeros(n/10);
        int dig=n%10;
        if(dig==0)
            return ans+1;
        else
            return ans;
        
    }

}




int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
