#include <bits/stdc++.h>
using namespace std;
int A[5][5],B[5];
int matrix(int x, int y){
	int tmp[5], k=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==x || j==y) continue;
			tmp[++k]=A[i][j];
		}
	}
	return tmp[1]*tmp[4]-tmp[2]*tmp[3];
}
int main(){
	cout<<"Enter the matrix: \n";
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>A[i][j];
        }
        cin>>B[i];
    }

    int co_factor[5][5],si=1;
    cout<<"co_factor Matrix: \n";
    for(int i=1;i<=3;i++){
    	for(int j=1;j<=3;j++){
    		co_factor[i][j]=si*A[i][j]*matrix(i,j);
    		cout<<co_factor[i][j]<<"\t";
    		si=si*(-1);
    	}
    	cout<<endl;
    }

    for(int i=1;i<=3;i++){
    	for(int j=1;j<=i;j++){
    		swap(co_factor[i][j],co_factor[j][i]);
    	}
    }


    cout<<"Adjacency Matrix: \n";
    for(int i=1;i<=3;i++){
    	for(int j=1;j<=3;j++){
    		cout<<co_factor[i][j]<<"\t";
    	}
    	cout<<endl;
    }

    cout<<"Inverse Matrix: \n";

    for(int i=1;i<=3;i++){
    	for(int j=1;j<=3;j++){
    		cout<<co_factor[i][j]<<"\t";
    	}
    	if(i==2) cout<<"* 1/"<<co_factor[1][1]+co_factor[1][2]+co_factor[1][3];
    	cout<<endl;
    }
	return 0;
}
