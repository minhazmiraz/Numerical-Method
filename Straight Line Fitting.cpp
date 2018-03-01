#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=0,y=0,x2=0,y2=0,xy=0;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i=1;i<=5;i++){
        int a,b;
        cout<<"Enter x"<<i<<": ";
        cin>>a;
        cout<<"Enter y"<<i<<": ";
        cin>>b;
        x+=a; x2+=a*a;
        y+=b; y2+=b*b;
        xy+=a*b;
    }

    int deno=(n*x2)-(x*x);

    cout<<"a: "<<((x2*y)-(x*xy))/(double)deno<<endl;
    cout<<"b: "<<((n*xy)-(x*y))/(double)deno<<endl;

    return 0;
}
