#include<unordered_map>
void PairSum(int *input, int n) {
    unordered_map<int,int>mp;
     for(int i=0;i<n;i++){
         int count=mp[-1*input[i]];
		while(count>0){
            cout<<-1*abs(input[i])<<" "<<abs(input[i])<<endl;
            count--;
        }
         mp[input[i]]++;
            
     }	 	
}

