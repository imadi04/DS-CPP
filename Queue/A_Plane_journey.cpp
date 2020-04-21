#include <iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n,m;
	cin >>n>>m;
	deque<int>people;
	deque<int>plane;										
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		people.push_back(t);
	}
		//cin>>people[i];
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		plane.push_back(t);
	}
	
	sort(people.begin(),people.end(),greater<int>());
	sort(plane.begin(),plane.end(),greater<int>());
	if(people[0]>plane[0]){
		cout<<"-1";
		exit(0);
	}
	int count=0;
	
	int ans;
	int k=0;
	while(people.size()){
		count++;
		for(int i=0;i<m;i++){
			if(!people.size())
				break;
			if(people[0]<=plane[i]){
				people.pop_front();
			}
			else{
				for(int j=m;j>=i;j--){
					if(!people.size())
					break;
				if(people.back()<=plane[j])
					people.pop_back();
				else
					break;
				}
				break;
			}
		}
	}
	ans=2*count-1;
	cout<<ans;
	return 0;		
}

