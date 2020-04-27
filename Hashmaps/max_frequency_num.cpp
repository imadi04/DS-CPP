#include<unordered_map>
#include<climits>
int highestFrequency(int *input, int n){	   	
	unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[input[i]]+=1;
    }
    int max=INT_MIN;
    int res=input[0];
    for(int i=0;i<n;i++){
        if(mp[input[i]]>max){
            max=mp[input[i]];
           res=input[i]; 
        }
    }
    return res;
}

