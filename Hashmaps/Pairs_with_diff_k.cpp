#include<unordered_map>
void printPairs(int *input, int n, int k) {
	// Write your code here
	unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[input[i]]++;
    }
    for(int i=0;i<n;i++){
        if(k==0){
            int t=mp[input[i]];
            int j=t*(t-1)/2;
            while(j--){
                cout<<input[i]<<" "<<input[i]<<endl;
            }
            mp[input[i]]=0;
        }
        else{
            int count1=mp[input[i]];
        int count2=mp[input[i]+k];
        int count3=mp[input[i]-k];
        //cout<<"c1:"<<count1<<" c2:"<<count2<<" c3:"<<count3<<endl;
        for(int j=0;j<(count1*count2);j++)
            cout<<input[i]<<" "<<input[i]+k<<endl;
        for(int m=0;m<(count1*count3);m++)
            cout<<input[i]-k<<" "<<input[i]<<endl;
        mp[input[i]]=0;  
        }
       
    }
}


