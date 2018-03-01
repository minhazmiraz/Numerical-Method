#include <bits/stdc++.h>
using namespace std;
int deg,co_ef[1000];
double X[1000],Y[1000];
double f(double x){
    return x*x*x+1;
}


int main(){
//    printf("Enter Degree: ");
//    cin>>deg;
//    for(int i=deg;i>=0;i--){
//        printf("Enter Co_ef of X^%d: ",i);
//        cin>>co_ef[i];
//    }

    printf("Enter upper limit: ");
    int up; cin>>up;

    printf("Enter lower limit: ");
    int lo; cin>>lo;

    int n;
    printf("Enter N: ");
    cin>>n;

    double h;
    h=(up-lo)/(double)n;

    X[0]=lo; X[n]=up;
    Y[0]=f(lo); Y[n]=f(up);

    for(int i=1;i<n;i++){
        X[i]=X[i-1]+h;
        Y[i]=f(X[i]);
    }

    double ans=Y[0]+Y[n];

    double three=0.0,two=0.0;
    for(int i=1;i<n;i++){
        if(i%3==0)
            three+=Y[i];
        else
            two+=Y[i];
    }
    ans+=(2*three)+(3*two);

    ans=ans*((3*h)/8);

    cout<<ans<<endl;
    return 0;
}
