#include <stdio.h>

double cubeRoot(double number){
    
    double start=0,end,mid;
    end = number;
    mid=(start + end)/2;
    double e = 0.10;
    
    while(mid*mid*mid != number){
        mid=(start + end)/2;
        if(mid*mid*mid < number){
            start = mid;
        }else if(mid*mid*mid > number){
            end = mid;
        }
    }
    return mid;
}

int main(){
    double num;

    printf("Provide a number: ");
    scanf("%lf",&num);
    printf("The cube root of the number is %.2lf\n",cubeRoot(num));

    return 0;
}