#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    if(n<=0)
        return 0;
    else{
        int ans=sumOfDigits(n/10);
        int dig=n%10;
        return dig+ans;
    }
}




int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
