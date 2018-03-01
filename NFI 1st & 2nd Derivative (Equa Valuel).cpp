#include <bits/stdc++.h>
using namespace std;
int main(){
    int x[100],y[10][100];
    double mult[]={1,1,11.0/12.0,5.0/6.0};
    for(int i=0;i<6;i++){
        x[i]=i+1;
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


    int h=x[1]-x[0], sign=1;
    double sum=0.0;
    for(int i=1;i<=4;i++){
        sum+=sign*y[i][0]*(1.0/i);
        sign*=-1;
    }

    cout<<"Ans of 1st Derivative: "<<(1.0/h)*sum<<endl;
    sum=0.0,sign=1;
    for(int i=2;i<=5;i++){
        sum+=sign*y[i][0]*mult[i-2];
        sign*=-1;
        //cout<<sum<<endl;
    }

    cout<<"Ans of 2nd Derivative: "<<(1.0/(h*h))*sum<<endl;

    return 0;
}
