#include<bits/stdc++.h>
using namespace std;

double f( double x, double y){
    return 3*x*x+1;
}

int main(){
    int n;
    double px,py,cx,cy,dest,h;
    cin>>px>>py>>h>>dest;
    n=(dest-px)/h;
    for(int i=1;i<=n;i++){
        cx=px+h;
        cy=py+h*f(px,py);
        px=cx; py=cy;
    }
    cout<<cy<<endl;
    return 0;
}
