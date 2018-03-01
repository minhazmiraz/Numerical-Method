#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int matrix(int jx, int jy, int jz){
    return (arr[1][jx]*arr[2][jy]*arr[3][jz])
        +(arr[1][jy]*arr[2][jz]*arr[3][jx])
        +(arr[1][jz]*arr[2][jx]*arr[3][jy])
        -(arr[1][jx]*arr[3][jy]*arr[2][jz])
        -(arr[3][jx]*arr[2][jy]*arr[1][jz])
        -(arr[2][jx]*arr[1][jy]*arr[3][jz]);
}

int main(){
    int x=0,y=0,x2=0,x3=0,x4=0,xy=0,x2y=0;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cout<<"Enter x"<<i<<": ";
        cin>>a;
        cout<<"Enter y"<<i<<": ";
        cin>>b;
        x+=a; x2+=a*a; x3+=a*a*a; x4+=a*a*a*a;
        y+=b; xy+=a*b; x2y+=a*a*b;
    }

    arr[1][1]=n; arr[1][2]=x; arr[1][3]=x2; arr[1][4]=y;
    arr[2][1]=x; arr[2][2]=x2; arr[2][3]=x3; arr[2][4]=xy;
    arr[3][1]=x2; arr[3][2]=x3; arr[3][3]=x4; arr[3][4]=x2y;

    int deno=matrix(1,2,3);
    cout<<"x: "<<matrix(4,2,3)/(double)deno<<endl;
    cout<<"y: "<<matrix(1,4,3)/(double)deno<<endl;
    cout<<"z: "<<matrix(1,2,4)/(double)deno<<endl;

    return 0;
}
