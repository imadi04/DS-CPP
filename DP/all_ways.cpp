/*Given two integers a and b. You need to find and return the count 
of possible ways in which we can represent the number a as the sum of 
unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
*/

#include<math.h>
int allWays(int x, int n,int curr_num=1,int curr_sum=0) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int result=0;
    int p=pow(curr_num,n);
    while(p+curr_sum<x){
        curr_num++;
        result+=allWays(x,n,curr_num,p+curr_sum);
        p=pow(curr_num,n);
    }
    if(p+curr_sum==x)
        result++;
    return result;
    
    
}