#include<algorithm>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int **ans=new int*[row];
    for(int i=0;i<row;i++)
        ans[i]=new int[col];
    for(int i=0;i<col;i++)
        if(arr[0][i]==0)
            ans[0][i]=1;
    for(int i=0;i<row;i++)
        if(arr[i][0]==0)
            ans[i][0]=1;
    int res=0;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]==0)
            	ans[i][j]=min(ans[i-1][j],min(ans[i][j-1],ans[i-1][j-1]))+1;
            else
                ans[i][j]=0;
            if(ans[i][j]>res)
                res=ans[i][j];
        }
    }
    /*for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            if(ans[i][j]>res)
                res=ans[i][j];
    }*/
   /* for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }*/
    return res;
    
}