/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make change for Value V using coins 
of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/


int countWaysToMakeChange(int denominations[], int numDenominations, int value,int **ans){
     if(value<0)
        return 0;
	if(value==0)//value==n   value+1,numDenominations
        return 1;
    if(numDenominations<=0 && value>=1)
        return 0;
    if(ans[value][numDenominations]!=-1)
        return ans[value][numDenominations];
    int output= countWaysToMakeChange(denominations,numDenominations,value-denominations[numDenominations-1],ans)
        +countWaysToMakeChange(denominations,numDenominations-1,value,ans);
	// return countWaysToMakeChange(denominations+1,numDenominations-1,value-denominations[0])
        // +countWaysToMakeChange(denominations+1,numDenominations-1,value);
    ans[value][numDenominations]=output;
    return output;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int **ans=new int*[value+1];
    for(int i=0;i<=value;i++){
        ans[i]=new int[numDenominations+1];
        for(int j=0;j<=numDenominations;j++)
            ans[i][j]=-1;
    }
    return countWaysToMakeChange(denominations,numDenominations,value,ans);
}