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
    cout<<"Enter the eqn: \n";
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cout<<"input x"<<i<<j<<": ";
            cin>>arr[i][j];
        }
        cout<<"input x"<<i<<"-const"<<": ";
        cin>>arr[i][4];
    }
    int deno=matrix(1,2,3);
    cout<<"x: "<<matrix(4,2,3)/(double)deno<<endl;
    cout<<"y: "<<matrix(1,4,3)/(double)deno<<endl;
    cout<<"z: "<<matrix(1,2,4)/(double)deno<<endl;
    return 0;
}
