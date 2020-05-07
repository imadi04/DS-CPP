#define M 1000000007
int balancedBTs(int h,int *ans) {
    if(h==0 || h==1)
        return 1;
    if(ans[h]!=-1)
        return ans[h];
    
    long a=balancedBTs(h-1,ans);
    long b=balancedBTs(h-2,ans);
    ans[h]=(a*(a+2*b))%M;
    int output=ans[h];
    
    //return (a*a)+(a*b)+(b*a);
    return output;
   

}

int binaryTreesOfHeightH(int h) {
    // Write your code here
	int *ans=new int[h+1];
    for(int i=0;i<=h;i++)
        ans[i]=-1;
    balancedBTs(h,ans);
}


