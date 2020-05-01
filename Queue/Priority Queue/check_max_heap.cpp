bool checkMaxHeap(int arr[], int n){
    for(int i=0;i<n;i++){
        int ch1=2*i+1;
        int ch2=2*i+2;
        if(ch1<n){
            if(arr[i]<arr[ch1])
                return false;
        }
        if(ch2<n){
            if(arr[i]<arr[ch2])
                return false;
        }
    }
    return true;
}
