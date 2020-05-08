/*

A thief wants to loot houses. He knows the amount of money in each house. 
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110

*/


using namespace std;
int getMaxMoney(int arr[], int n,int *ans){
    if(n<=0)
        return 0;
    if(ans[n]!=-1)
        return ans[n];
    
    int x=arr[0]+getMaxMoney(arr+2,n-2,ans);
    int y=arr[1]+getMaxMoney(arr+3,n-3,ans);
    ans[n]=max(x,y);
    return ans[n];
}
int getMaxMoney(int arr[], int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;
    getMaxMoney(arr,n,ans);
    

}
