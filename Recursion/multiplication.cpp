#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n==1)
        return m;
    else{
        return m+multiplyNumbers(m,abs(n)-1);
    }
}





int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
