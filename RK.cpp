#include <bits/stdc++.h>
using namespace std;
double f(double x, double y){
    return x*x+y*y;
}

int main(){
    int n;
    double px, py, cx, cy, h, dest, m1, m2, m3,m4;
    cin>>px>>py>>h>>dest;
    n=(dest-px)/h;
    for(int i=1;i<=n;i++){
        cx=px+h;
        m1=f(px,py);
        m2=f(px+h/2, py+(m1*h)/2);
        m3=f(px+h/2, py+(m2*h)/2);
        m4=f(px+h, py+(m3*h));
        cy=py+(m1+2*m2+2*m3+m4)*(h/6);
        px=cx; py=cy;
    }
    cout<<cy<<endl;
    return 0;
}
