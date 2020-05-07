/*
A child is running up a staircase with n steps and can hop 
either 1 step, 2 steps or 3 steps at a time. Implement a method 
to count how many possible ways the child can run up to the stairs. 
You need to return all possible number of ways.
Time complexity of your code should be O(n).

*/


long staircase(int n,long *ans){
    if(n==0)
        return 1;
    if(n==1 || n==2)
        return n;
    if(ans[n]!=-1)
        return ans[n];
    long output=staircase(n-1,ans)+staircase(n-2,ans)+staircase(n-3,ans);
    ans[n]=output;
    return output;
}

long staircase(int n){
    long *ans=new long[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;
    staircase(n,ans);
    
    
    
}
