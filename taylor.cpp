#include <bits/stdc++.h>
using namespace std;
double d(int der, double x, double y){
    if(der==1) return x+y;
    else if(der==2) return 1+y;
    else return y;
}

double f(double x, double y, double h){
    double ans=y, fact=1.0, dery=y, tmp=1.0;
    for(int i=1;i<=4;i++){
        dery=d(i,x,dery);
        fact=fact*i; tmp*=h;
        ans+=(tmp/fact)*dery;
    }

    return ans;
}

int main(){
    double x,y,h;
    cin>>x>>y>>h;
    while(x<=1.3){
        cout<<x<<": "<<y<<endl;
        y=f(x,y,h);
        x+=h;
    }
    return 0;
}
