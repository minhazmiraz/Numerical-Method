#include <bits/stdc++.h>
using namespace std;
int x[100],y[10][100];
double Umain;
double mult[]={0,0,1,1,1.0/12.0,1.0/12.0};

double fact(int x){
    double mul=1;
    for(int i=x;i>0;i--)
        mul*=i;
    return mul;
}

double val_Of_U1(int i){
    if(i<=1)
        return 1;
    else if(i==2){
        return 2*Umain-1;
    } else if(i==3){
        return 3*Umain*Umain-6*Umain+2;
    } else if(i==4){
        return 4*Umain*Umain*Umain-18*Umain*Umain+22*Umain-6;
    } else if(i==5){
        double val=0;
        val+=5*Umain*Umain*Umain*Umain;
        val-=40*Umain*Umain*Umain;
        val+=105*Umain*Umain;
        val-=100*Umain;
        val+=24;
        return val;
    }
}


double val_Of_U2(int i){
    if(i<=1){
        return 0;
    } else if(i==2){
        return 1;
    } else if(i==3){
        return Umain-1;
    } else if(i==4){
        return 6*Umain*Umain-9*Umain+11;
    } else if(i==5){
        double val=0;
        val+=2*Umain*Umain*Umain;
        val-=12*Umain*Umain;
        val+=21*Umain;
        val-=10;
        return val;
    }
}

int main(){
    cout<<"Enter the point: \n";
    double point;
    cin>>point;
    cout<<"Enter the value of X and Y: \n";
    for(int i=0;i<5;i++){
        cin>>x[i]>>y[0][i];
    }
    for(int i=1;i<5;i++){
        for(int j=0;j<5-i;j++){
            y[i][j]=y[i-1][j+1]-y[i-1][j];
        }
    }

    for(int i=0;i<5;i++) cout<<x[i]<<"       ";
    cout<<endl;

    for(int i=0;i<5;i++){
        for(int j=1;j<=i;j++) cout<<"    ";
        for(int j=0;j<5-i;j++){
            cout<<y[i][j]<<"       ";
        }
        cout<<endl;
    }

    double sum=0.0;
    int h=x[1]-x[0], sign=1;
    Umain=(point-x[0])/h;
    for(int i=1;i<=4;i++){
        sum+=val_Of_U1(i)*y[i][0]*(1.0/fact(i));
    }

    cout<<"Ans of 1st Derivative: "<<(1.0/h)*sum<<endl;
    sum=0.0;
    for(int i=2;i<=4;i++){
        sum+=val_Of_U2(i)*y[i][0]*mult[i];
    }

    cout<<"Ans of 2nd Derivative: "<<(1.0/(h*h))*sum<<endl;

    return 0;
}
