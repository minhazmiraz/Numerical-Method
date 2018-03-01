#include <bits/stdc++.h>
using namespace std;
#define error 0.0005
int a[100],n;

double f(double x){ //Using Horner's Rule
    double ans=0.0;
    for(int i=n;i>=0;i--){
        ans=(ans*x)+a[i];
    }
    return ans;
}

double secant(double x, double y){
    double x1=x, x2=y, x3=0.0;
    int i=1;
    while(1){
        printf("I-%d: \n",i);
        printf("X1: %lf  F(x1): %lf\n",x1,f(x1));
        printf("X2: %lf  F(x2): %lf\n",x2,f(x2));
        x3=((f(x2)*x1)-(f(x1)*x2))/(f(x2)-f(x1));
        printf("X3: %lf  F(x3): %lf\n\n",x3,f(x3));

        if(fabs(x2-x3)<=error) break;

        x1=x2, x2=x3;
        i++;
    }
    return x3;

}

int main(){
    printf("Enter the degree of eqn: ");
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter Your Initial Value: ");
    double x1,x2;
    scanf("%lf%lf",&x1,&x2);
    double ans=secant(x1,x2);
    printf("Root: %lf\n",ans);
    printf("F: %lf\n",f(ans));
    return 0;
}
