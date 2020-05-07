/*

Given a positive integer n, find the minimum number of steps s, 
that takes n to 1. You can perform any one of the following 3 steps.
1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ). 

Sample Input 1 :
4
Sample Output 1 :
2 
Sample Output 1 Explanation :
For n = 4
Step 1 : n = 4/2 = 2
Step 2 : n = 2/2 = 1
 
*/

//Brute-force:
int countStepsTo1(int n){
    int x=INT_MAX,y=INT_MAX,z;
    if(n==1)
        return 0;
     z=countStepsTo1(n-1);
    if(n%2==0)
        x=countStepsTo1(n/2);
	if(n%3==0)
        y=countStepsTo1(n/3);
   
   return 1+min(z,min(x,y));

}


/********************************************************************************/
//memoisation
int countStepsTo1(int n,int arr[]){
    if(n==1)
        return 0;
    if(arr[n]!=-1)
        return arr[n];
    int x=countStepsTo1(n-1,arr);
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0)
        y=countStepsTo1(n/2,arr);
    if(n%3==0)
        z=countStepsTo1(n/3,arr);
    int output=1+min(x,min(y,z));
    arr[n]=output;
    return output;
}

int countStepsTo1(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;
    countStepsTo1(n,ans);

}

/***********************************************/