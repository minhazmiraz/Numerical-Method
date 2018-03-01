#include <bits/stdc++.h>
using namespace std;

int main(){
    printf("Enter degree of the eqn: ");
    int n,x;
    scanf("%d",&n);
    int ans=0;
    int a[100],b[100];

    //taking input of a[] and root
    for(int i=n;i>=0;i--){
        printf("Input a%d: ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter root: ");
    scanf("%d",&x);

    // Counting b[] and printing
    b[n]=0;
    printf("b%d: %d",n,b[n]);
    for(int i=n;i>0;i--){
        b[i-1]=a[i]+(x*b[i]);
        printf("b%d: %d\n",i-1,b[i-1]);
    }
    return 0;
}
