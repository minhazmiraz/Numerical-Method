#include <bits/stdc++.h>
using namespace std;
#define error 0.0005
int a[100],n;

double f(double x){ // Using Horner's
    double ans=0.0;
    for(int i=n;i>=0;i--){
        ans=(ans*x)+a[i];
    }
    return ans;
}

double bisection(double x, double y){
    double x1=x, x2=y;
    int i=1;
    while(fabs(x1-x2)>error){
        printf("I-%d: \n",i);
        printf("X1: %lf  F(x1): %lf\n",x1,f(x1));
        printf("X2: %lf  F(x2): %lf\n",x2,f(x2));
        double x0=(x1+x2)/2.0;
        printf("X0: %lf  F(x0): %lf\n\n",x0,f(x0));

        if(f(x1)*f(x0)>0)
            x1=x0;
        else if(f(x1)*f(x0)<0)
            x2=x0;
        i++;
    }
    return (x1+x2)/2.0;

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
    double ans=bisection(x1,x2);
    printf("Root: %lf\n",ans);
    printf("F: %lf\n",f(ans));
    return 0;
}
