int knapsack(int* weights, int* values, int n, int maxWeight){
	 int **ans=new int*[2];
    
    for(int i=0;i<2;i++){
        ans[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
            ans[i][j]=-1;
    }
    for(int i = 0 ; i <=n ; i++){
        for(int j = 0 ; j<= maxWeight ; j++){
            if(i==0 || j==0){
                ans[1][j] = 0 ; 
            }
            else if(j>=weights[i-1]){
                ans[1][j] = max(ans[0][j] , ans[0][j-weights[i-1]] + values[i-1]) ; 
            }
            else{
                ans[1][j] = ans[0][j]; 
            }
        }
        for(int j = 0 ; j<= maxWeight; j++){
            ans[0][j] = ans[1][j] ; 
        }
    }
    return ans[1][maxWeight] ;
   // knapsack(weights,values,n,maxWeight,ans);

}