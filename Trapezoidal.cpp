#include <bits/stdc++.h>
using namespace std;
int deg,co_ef[1000];
double X[1000],Y[1000];
double f(double x){
    return 1/x;
}


int main(){
    printf("Enter upper limit: ");
    int up; cin>>up;

    printf("Enter lower limit: ");
    int lo; cin>>lo;

    int n = up-lo;

    double h;
    h=(up-lo)/(double)n;

    X[0]=lo; X[n]=up;
    Y[0]=f(lo); Y[n]=f(up);

    for(int i=1;i<n;i++){
        X[i]=X[i-1]+h;
        Y[i]=f(X[i]);
    }

    double ans=Y[0]+Y[n];

    double four=0.0,two=0.0;
    for(int i=1;i<n;i++){
        if(i%2==0)
            two+=Y[i];
        else
            four+=Y[i];
    }
    ans+=(4*four)+(2*two);

    ans=ans*(h/3);

    cout<<ans<<endl;
    return 0;
}
