#include <bits/stdc++.h>
using namespace std;
double A[100][100],B[100];

void swp(int x){
	cout<<x<<endl;
	for(int i=x+1;i<=3;i++){
		if(A[i][x]!=0){
			swap(A[x][1],A[i][1]);
			swap(A[x][2],A[i][2]);
			swap(A[x][3],A[i][3]);
			swap(B[x],B[i]);
		}
	}
}

void eliminate(int x){
	double mul1=A[x][x];
	for(int i=x+1;i<=3;i++){
		double mul2=A[i][x];
		for(int j=1;j<=3;j++){
			A[i][j]=(mul1*A[i][j])-(mul2*A[x][j]);
		}
		B[i]=(mul1*B[i])-(mul2*B[x]);
	}
}

int main() {
    //ios_base::sync_with_stdio(0);

	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin>>A[i][j];
		}
		cin>>B[i];
	}

	for(int i=1;i<3;i++){
		if(A[i][i]==0){
			swp(i);
		}
		eliminate(i);
	}

	int ans[5];
	for(int i=3;i>0;i--){
		int tmp=B[i];
		for(int j=3;j>i;j--){
			tmp-=A[i][j]*ans[j];
		}
		ans[i]=tmp/A[i][i];
	}

	cout<<"x: "<<ans[1]<<endl;
	cout<<"y: "<<ans[2]<<endl;
	cout<<"z: "<<ans[3]<<endl;
    return 0;
}
