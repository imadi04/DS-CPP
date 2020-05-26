#include<climits>
int mcm(int* p, int n){
    int **m=new int*[n+1];
    for(int i=0;i<n+1;i++){
        m[i]=new int[n+1];
    }
     for (int i = 1; i < n+1; i++) 
        m[i][i] = 0;
   /* int **s=new int*[n+1];
    for(int i=0;i<=n;i++){
        s[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            s[i][j]=0;
    }*/
   
    int temp,j;
    for(int d=2;d<n+1;d++){
        for(int i=1;i<n-d+2;i++){
            j=i+d-1;
            m[i][j]=INT_MAX;
           
            for(int k=i;k<=j-1;k++){
                 temp=m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if(temp<m[i][j]){
                    m[i][j]=temp;
                }
                
            }
        }
    }
    return m[1][n];
}
