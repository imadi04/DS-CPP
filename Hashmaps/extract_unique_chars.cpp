#include<unordered_map>
#include<string>
string uniqueChar(char *str){
    // Write your code here
	string output="";
    int k=0;
	unordered_map<int, bool> seen;
	for (int i = 0; str[i]!='\0'; i++) {
		if (seen.count(str[i])) {
			continue;
		}
		seen[str[i]] = true;
		output+=str[i];
	}
	return output;
}