#include <bits/stdc++.h>
using namespace std;
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

	for(int i=1;i<=eqn;i++){
        double tmp=A[i][i],tmp2;
		for(int j=1;j<=var;j++)
			A[i][j]=(A[i][j]/tmp);	//Normalise using Pivot A[i][i]
		B[i]=B[i]/tmp;


		//Eliminating Variavale
		for(int j=1;j<=eqn;j++){
			if(j!=i){
				tmp=A[i][i];
				tmp2=A[j][i];

				for(int k=1;k<=var;k++){
					A[j][k]=(A[j][k]*tmp-A[i][k]*tmp2);
				}
				B[j]=(B[j]*tmp-B[i]*tmp2);


			}
		}
	}


	cout<<"Final Answer: \n";
	for(int i=1;i<=eqn;i++){
		for(int j=1;j<=var;j++){
			cout<<A[i][j]<<"\t";
		}
		cout<<B[i]<<endl;
	}

	return 0;
}
