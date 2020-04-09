/*You have made a smartphone app and want to set its price such that 
the profit earned is maximised. There are certain buyers who will buy 
your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of buyers 
and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are 
N number of buyers. So maximum profit you can earn is :m * x
where m is total number of buyers whose budget is greater than or equal to x.

Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. 
For both prices, you can get the profit Rs. 60.
*/
#include <iostream>
using namespace std;
#include<algorithm>


int maximumProfit(int budget[], int n) {
	int *price=new int[n];
    sort(budget,budget+n);
    for(int i=0;i<n;i++){
        price[i]=budget[i]*(n-i);
    }
    sort(price,price+n);
    return price[n-1];
    // Write your code here
	
}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
