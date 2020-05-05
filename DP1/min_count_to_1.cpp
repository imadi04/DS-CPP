/*

Given an integer N, find and return the count of minimum numbers, 
sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.

Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.

*/

int minCount(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    for(int i=4;i<=n;i++){
        ans[i]=i;
        for(int j=1;j<=i/2;j++){
            int t=j*j;
            if(t>i)
                break;
            ans[i]=min(ans[i],1+ans[i-t]);
        }
    }
    int res=ans[n];
    delete[] ans;
    return res;
}