#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cout<<"Enter Your Number: ";
	cin>>str; //1.1255465
	int n;
	cout<<"Precision: ";
	cin>>n;

	//getting the position of the decimal point
	int point=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='.'){
			point=i;
			break;
		}
	}

	int flag=0;
	if(str[point+n+1]>'5'){
		int i=point+n;
		while(str[i]=='9'){     //while loop is only
			str[i]='0';         //for those case like 9.99999 or 3.99999
			if(i==0)
				flag=1; //for case : 9.999999
			i--;
			if(str[i]=='.')
				i--;
		}
		if(!flag)
			str[i]++;
		else
			cout<<"1";
		cout<<str.substr(0,point+n+1)<<endl;
	} else if(str[point+n+1]=='5'){
		int temp=str[point+n]-'0';
		if(temp%2!=0){
			int i=point+n;
			while(str[i]=='9'){
				str[i]='0';
				if(i==0)
					flag=1; //for case : 9.999999
				i--;
				if(str[i]=='.')
					i--;
			}
			if(!flag)
				str[i]++;
			else
				cout<<"1";
			cout<<str.substr(0,point+n+1)<<endl;
		} else{
			cout<<str.substr(0,point+n+1)<<endl;
		}
	} else{
		cout<<str.substr(0,point+n+1)<<endl;
	}
	return 0;
}
