#include <bits/stdc++.h>
using namespace std;
int main(){
    int x[100],y[10][100];

    for(int i=0;i<6;i++){
        x[i]=i;
        y[0][i]=x[i]*x[i]*x[i];
    }
    for(int i=1;i<6;i++){
        for(int j=0;j<6-i;j++){
            y[i][j]=y[i-1][j+1]-y[i-1][j];
        }
    }
    for(int i=0;i<6;i++) cout<<x[i]<<"       ";
    cout<<endl;

    for(int i=0;i<6;i++){
        for(int j=1;j<=i;j++) cout<<"    ";
        for(int j=0;j<6-i;j++){
            cout<<y[i][j]<<"       ";
        }
        cout<<endl;
    }
    return 0;
}
