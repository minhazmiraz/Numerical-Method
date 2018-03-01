#include <bits/stdc++.h>
using namespace std;
#define error 0.0005
int a[2][100],n;

double f(int j, double x){ //Using Horner's Rule
    double ans=0.0;
    for(int i=n;i>=0;i--){
        ans=(ans*x)+a[j][i];
    }
    return ans;
}


double Newton_Raphson(double x0){
    double x1=0.0;
    int i=1;
    while(1){
        printf("I-%d: \n",i);
        printf("X0: %lf  F(x0): %lf\n",x0,f(0,x0));
        x1=x0-(f(0,x0)/f(1,x0));
        printf("X1: %lf  F(x1): %lf\n\n",x1,f(0,x1));

        if(fabs(x1-x0)<=error) break;

        x0=x1;
        i++;
    }
    return x1;

}

int main(){
    printf("Enter the degree of eqn: ");
    scanf("%d",&n);
    a[1][n]=0;
    for(int i=n;i>=0;i--){
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&a[0][i]);
        a[1][i-1]=a[0][i]*i;
    }

    printf("Enter Your Initial Value: ");
    double x0;
    scanf("%lf",&x0);
    double ans=Newton_Raphson(x0);
    printf("Root: %lf\n",ans);
    return 0;
}
