#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
//newton raphson method 
float f(float x){
    return x*x*x-8*x-4;
}

float differentiate(float x){
     return 3*x*x-8;
}

int main(){
    int maxIteration,i;
    float x1,x2,x0,x;
    printf("Enter maximum number of iterations ");
    scanf("%d",&maxIteration);
    //now we will compute x1 and x2
    do{
        printf("Enter the value of x1 and x2  ");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2)>0){
            printf("Boundary values are Invalid ");
            continue;
        }
        else{
            printf("Roots lie between %f %f\n",x1,x2);
            break;
        }
    }while(1);

    if(fabs(f(x1))<fabs(f(x2))){
        x0=x1;
    }
    else{
        x1=x2;
    }

    for(i=1;i<=maxIteration;i++){
        x=x0-(f(x0)/differentiate(x0));
        if(fabs(x-x0)<EPSILON){
            printf("Iterations %d final root=%f\n",i,x);
            return 0;
        }
        printf("Iterations=%d Roots=%f\n",i,x);
        x0=x;
    }
    printf("Roots=%f Total Iteration=%d",x,--i);
}