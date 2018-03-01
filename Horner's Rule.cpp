#include <bits/stdc++.h>
using namespace std;

int main(){
    printf("Enter degree of the eqn: ");
    int n,x;
    scanf("%d",&n);
    printf("Enter x: ");
    scanf("%d",&x);
    int ans=0;
    for(int i=n;i>=0;i--){
        int a;
        printf("Input a%d: ",i);
        scanf("%d",&a);     //taking input
        ans=(ans*x)+a;      //counting ans
    }
    printf("Ans: %d\n",ans);
    return 0;
}
