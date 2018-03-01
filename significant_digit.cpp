#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int i, lead=0, tail=0;

	//Count leading zero
	i=0;
	while(str[i]=='0' || str[i]=='.'){
		if(str[i]!='.')
			lead++;
		i++;
	}

	//Count tailing zero
	i=str.length()-1;
	while(str[i]=='0' || str[i]=='.'){
		if(str[i]!='.')
			tail++;
		i--;
	}

    //checking is there any decimal point
	int pflag=0;
	for(int j=0;j<str.length();j++){
		if(str[j]=='.')
			pflag=1;
	}

    //Counting significant digit
	int len=str.length();
	len-=lead;      // substract leading zeros

	if(pflag!=1)
		len-=tail;  //if point not found substract tailing zeros
	else
		len-=1;     //else substract 1 for decimal point

	cout<<len<<endl;
	return 0;
}
