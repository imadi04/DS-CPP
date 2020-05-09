using namespace std;

 int lis(int arr[], int n) { 
     int *ans=new int[n];
     ans[0]=1;
     for(int i=1;i<n;i++){
         ans[i]=1;
         for(int j=i-1;j>=0;j--){
             if(arr[j]>=arr[i])
                 continue;
             int t=ans[j]+1;
             if(t>ans[i])
                 ans[i]=t;
         }
     }
     int best=0;
     for(int i=0;i<n;i++){
         if(best<ans[i])
             best=ans[i];
     }
     delete [] ans;
     return best;
 }