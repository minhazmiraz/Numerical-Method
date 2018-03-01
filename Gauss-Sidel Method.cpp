#include <bits/stdc++.h>
using namespace std;
#define err 0.005
double A[1000][1000], B[1000];
int main(){
	printf("Enter number of variable: ");
	int var; cin>>var;
	printf("Enter number of Equation: ");
	int eqn; cin>>eqn;

	//	AX=B
	for(int i=1;i<=eqn;i++){
		for(int j=1;j<=var;j++){
			cin>>A[i][j];
		}
		cin>>B[i];
	}


	double x[var+5];
	memset(x,0,sizeof x);
	int itr=0;
	do{
        cout<<"I-"<<itr+1<<": "<<endl;
		for(int i=1;i<=eqn;i++){
			double sum=B[i];
			for(int j=1;j<=var;j++){
				if(i==j) continue;
				sum-=A[i][j]*x[j];
                //cout<<A[i][j]<<" "<<x[j]<<" "<<sum<<endl;
			}
			x[i]=sum/A[i][i];
		}
		itr++;
        for(int i=1;i<=var;i++) cout<<x[i]<<"\t";
        cout<<endl;
        if(itr>=10) break;
	} while(x[var-1]-x[var]>err);
	return 0;
}
